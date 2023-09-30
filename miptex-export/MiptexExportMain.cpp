#include "MiptexFile.h"

#include <LoadPalette.h>
#include <PaletteImage.h>
#include <QuakePalette.h>
#include <StbImage.h>
#include <Transparency.h>
#include <WriteImage.h>

#include <molecular/util/FileStreamStorage.h>
#include <molecular/util/StringUtils.h>
#include <molecular/util/CommandLineParser.h>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

using namespace molecular;
using namespace molecular::util;

int Main(int argc, char** argv)
{
	CommandLineParser cmd;
	CommandLineParser::PositionalArg<std::string> inFileName(cmd, "input file", "Input image");
	CommandLineParser::PositionalArg<std::string> outFileName(cmd, "output file", "Output MIPTEX file");
	CommandLineParser::Flag dither(cmd, "dither", "Enable dithering");
	CommandLineParser::Option<std::string> palette(cmd, "palette", "Palette to use instead of default Quake palette. Can be image or lump.");
	CommandLineParser::Option<std::string> previewOutput(cmd, "preview-output", "Write quantized image back to file");
	CommandLineParser::HelpFlag help(cmd);

	try
	{
		cmd.Parse(argc, argv);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		cmd.PrintHelp();
		return EXIT_FAILURE;
	}

	const uint8_t* paletteData = quakePalette;
	std::vector<uint8_t> loadedPalette;
	if(palette)
	{
		loadedPalette = LoadPaletteFile(palette->c_str());
		paletteData = loadedPalette.data();
	}

	FileWriteStorage outFile(outFileName->c_str());
	StbImage textureImage(inFileName->c_str(), 4);
	const auto width = textureImage.GetWidth();
	const auto height = textureImage.GetHeight();

	if(width % 8 != 0 || height % 8 != 0)
	{
		std::cerr << "Width and height must be multiples of 8, preferrably powers of two" << std::endl;
		return EXIT_FAILURE;
	}

	auto [color, alpha] = SplitColorAndAlpha(textureImage.Data(), width, height);

	std::vector<uint8_t> indexedImage = ConvertToIndexed(color.data(), width, height, paletteData, dither);
	SetTransparency(indexedImage, alpha);

	if(previewOutput)
	{
		auto previewImage = ConvertToRgb(indexedImage.data(), width, height, paletteData);
		WriteRgbImage(previewOutput->c_str(), previewImage.data(), width, height);
	}

	MiptexFile outMiptexFile(outFile);
	outMiptexFile.WriteHeader(StringUtils::FileNameWithoutExtension(*inFileName).c_str(), width, height);
	outMiptexFile.WriteMip(indexedImage.data(), indexedImage.size());

	int newWidth = width / 2;
	int newHeight = height / 2;
	for(int i = 0; i < 3; ++i)
	{
		std::vector<uint8_t> newImage(newWidth * newHeight * 4);
		stbir_resize_uint8_srgb_edgemode(textureImage.Data(), width, height, width * 4, newImage.data(), newWidth, newHeight, newWidth * 4, 4, 3, 0, STBIR_EDGE_WRAP);
		auto [color, alpha] = SplitColorAndAlpha(newImage.data(), newWidth, newHeight);

		indexedImage = ConvertToIndexed(color.data(), newWidth, newHeight, paletteData, dither);
		SetTransparency(indexedImage, alpha);
		outMiptexFile.WriteMip(indexedImage.data(), indexedImage.size());

		newWidth /= 2;
		newHeight /= 2;
	}

	return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	try
	{
		return Main(argc, argv);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
