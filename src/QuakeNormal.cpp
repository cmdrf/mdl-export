/*	QuakeNormal.cpp

MIT License

Copyright (c) 2023 Fabian Herb

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <molecular/util/Vector3.h>

using namespace molecular::util;

static const std::vector<Vector3> normals = {
	Vector3(-0.525731,  0.000000,  0.850651),
	Vector3(-0.442863,  0.238856,  0.864188),
	Vector3(-0.295242,  0.000000,  0.955423),
	Vector3(-0.309017,  0.500000,  0.809017),
	Vector3(-0.162460,  0.262866,  0.951056),
	Vector3( 0.000000,  0.000000,  1.000000),
	Vector3( 0.000000,  0.850651,  0.525731),
	Vector3(-0.147621,  0.716567,  0.681718),
	Vector3( 0.147621,  0.716567,  0.681718),
	Vector3( 0.000000,  0.525731,  0.850651),
	Vector3( 0.309017,  0.500000,  0.809017),
	Vector3( 0.525731,  0.000000,  0.850651),
	Vector3( 0.295242,  0.000000,  0.955423),
	Vector3( 0.442863,  0.238856,  0.864188),
	Vector3( 0.162460,  0.262866,  0.951056),
	Vector3(-0.681718,  0.147621,  0.716567),
	Vector3(-0.809017,  0.309017,  0.500000),
	Vector3(-0.587785,  0.425325,  0.688191),
	Vector3(-0.850651,  0.525731,  0.000000),
	Vector3(-0.864188,  0.442863,  0.238856),
	Vector3(-0.716567,  0.681718,  0.147621),
	Vector3(-0.688191,  0.587785,  0.425325),
	Vector3(-0.500000,  0.809017,  0.309017),
	Vector3(-0.238856,  0.864188,  0.442863),
	Vector3(-0.425325,  0.688191,  0.587785),
	Vector3(-0.716567,  0.681718, -0.147621),
	Vector3(-0.500000,  0.809017, -0.309017),
	Vector3(-0.525731,  0.850651,  0.000000),
	Vector3( 0.000000,  0.850651, -0.525731),
	Vector3(-0.238856,  0.864188, -0.442863),
	Vector3( 0.000000,  0.955423, -0.295242),
	Vector3(-0.262866,  0.951056, -0.162460),
	Vector3( 0.000000,  1.000000,  0.000000),
	Vector3( 0.000000,  0.955423,  0.295242),
	Vector3(-0.262866,  0.951056,  0.162460),
	Vector3( 0.238856,  0.864188,  0.442863),
	Vector3( 0.262866,  0.951056,  0.162460),
	Vector3( 0.500000,  0.809017,  0.309017),
	Vector3( 0.238856,  0.864188, -0.442863),
	Vector3( 0.262866,  0.951056, -0.162460),
	Vector3( 0.500000,  0.809017, -0.309017),
	Vector3( 0.850651,  0.525731,  0.000000),
	Vector3( 0.716567,  0.681718,  0.147621),
	Vector3( 0.716567,  0.681718, -0.147621),
	Vector3( 0.525731,  0.850651,  0.000000),
	Vector3( 0.425325,  0.688191,  0.587785),
	Vector3( 0.864188,  0.442863,  0.238856),
	Vector3( 0.688191,  0.587785,  0.425325),
	Vector3( 0.809017,  0.309017,  0.500000),
	Vector3( 0.681718,  0.147621,  0.716567),
	Vector3( 0.587785,  0.425325,  0.688191),
	Vector3( 0.955423,  0.295242,  0.000000),
	Vector3( 1.000000,  0.000000,  0.000000),
	Vector3( 0.951056,  0.162460,  0.262866),
	Vector3( 0.850651, -0.525731,  0.000000),
	Vector3( 0.955423, -0.295242,  0.000000),
	Vector3( 0.864188, -0.442863,  0.238856),
	Vector3( 0.951056, -0.162460,  0.262866),
	Vector3( 0.809017, -0.309017,  0.500000),
	Vector3( 0.681718, -0.147621,  0.716567),
	Vector3( 0.850651,  0.000000,  0.525731),
	Vector3( 0.864188,  0.442863, -0.238856),
	Vector3( 0.809017,  0.309017, -0.500000),
	Vector3( 0.951056,  0.162460, -0.262866),
	Vector3( 0.525731,  0.000000, -0.850651),
	Vector3( 0.681718,  0.147621, -0.716567),
	Vector3( 0.681718, -0.147621, -0.716567),
	Vector3( 0.850651,  0.000000, -0.525731),
	Vector3( 0.809017, -0.309017, -0.500000),
	Vector3( 0.864188, -0.442863, -0.238856),
	Vector3( 0.951056, -0.162460, -0.262866),
	Vector3( 0.147621,  0.716567, -0.681718),
	Vector3( 0.309017,  0.500000, -0.809017),
	Vector3( 0.425325,  0.688191, -0.587785),
	Vector3( 0.442863,  0.238856, -0.864188),
	Vector3( 0.587785,  0.425325, -0.688191),
	Vector3( 0.688191,  0.587785, -0.425325),
	Vector3(-0.147621,  0.716567, -0.681718),
	Vector3(-0.309017,  0.500000, -0.809017),
	Vector3( 0.000000,  0.525731, -0.850651),
	Vector3(-0.525731,  0.000000, -0.850651),
	Vector3(-0.442863,  0.238856, -0.864188),
	Vector3(-0.295242,  0.000000, -0.955423),
	Vector3(-0.162460,  0.262866, -0.951056),
	Vector3( 0.000000,  0.000000, -1.000000),
	Vector3( 0.295242,  0.000000, -0.955423),
	Vector3( 0.162460,  0.262866, -0.951056),
	Vector3(-0.442863, -0.238856, -0.864188),
	Vector3(-0.309017, -0.500000, -0.809017),
	Vector3(-0.162460, -0.262866, -0.951056),
	Vector3( 0.000000, -0.850651, -0.525731),
	Vector3(-0.147621, -0.716567, -0.681718),
	Vector3( 0.147621, -0.716567, -0.681718),
	Vector3( 0.000000, -0.525731, -0.850651),
	Vector3( 0.309017, -0.500000, -0.809017),
	Vector3( 0.442863, -0.238856, -0.864188),
	Vector3( 0.162460, -0.262866, -0.951056),
	Vector3( 0.238856, -0.864188, -0.442863),
	Vector3( 0.500000, -0.809017, -0.309017),
	Vector3( 0.425325, -0.688191, -0.587785),
	Vector3( 0.716567, -0.681718, -0.147621),
	Vector3( 0.688191, -0.587785, -0.425325),
	Vector3( 0.587785, -0.425325, -0.688191),
	Vector3( 0.000000, -0.955423, -0.295242),
	Vector3( 0.000000, -1.000000,  0.000000),
	Vector3( 0.262866, -0.951056, -0.162460),
	Vector3( 0.000000, -0.850651,  0.525731),
	Vector3( 0.000000, -0.955423,  0.295242),
	Vector3( 0.238856, -0.864188,  0.442863),
	Vector3( 0.262866, -0.951056,  0.162460),
	Vector3( 0.500000, -0.809017,  0.309017),
	Vector3( 0.716567, -0.681718,  0.147621),
	Vector3( 0.525731, -0.850651,  0.000000),
	Vector3(-0.238856, -0.864188, -0.442863),
	Vector3(-0.500000, -0.809017, -0.309017),
	Vector3(-0.262866, -0.951056, -0.162460),
	Vector3(-0.850651, -0.525731,  0.000000),
	Vector3(-0.716567, -0.681718, -0.147621),
	Vector3(-0.716567, -0.681718,  0.147621),
	Vector3(-0.525731, -0.850651,  0.000000),
	Vector3(-0.500000, -0.809017,  0.309017),
	Vector3(-0.238856, -0.864188,  0.442863),
	Vector3(-0.262866, -0.951056,  0.162460),
	Vector3(-0.864188, -0.442863,  0.238856),
	Vector3(-0.809017, -0.309017,  0.500000),
	Vector3(-0.688191, -0.587785,  0.425325),
	Vector3(-0.681718, -0.147621,  0.716567),
	Vector3(-0.442863, -0.238856,  0.864188),
	Vector3(-0.587785, -0.425325,  0.688191),
	Vector3(-0.309017, -0.500000,  0.809017),
	Vector3(-0.147621, -0.716567,  0.681718),
	Vector3(-0.425325, -0.688191,  0.587785),
	Vector3(-0.162460, -0.262866,  0.951056),
	Vector3( 0.442863, -0.238856,  0.864188),
	Vector3( 0.162460, -0.262866,  0.951056),
	Vector3( 0.309017, -0.500000,  0.809017),
	Vector3( 0.147621, -0.716567,  0.681718),
	Vector3( 0.000000, -0.525731,  0.850651),
	Vector3( 0.425325, -0.688191,  0.587785),
	Vector3( 0.587785, -0.425325,  0.688191),
	Vector3( 0.688191, -0.587785,  0.425325),
	Vector3(-0.955423,  0.295242,  0.000000),
	Vector3(-0.951056,  0.162460,  0.262866),
	Vector3(-1.000000,  0.000000,  0.000000),
	Vector3(-0.850651,  0.000000,  0.525731),
	Vector3(-0.955423, -0.295242,  0.000000),
	Vector3(-0.951056, -0.162460,  0.262866),
	Vector3(-0.864188,  0.442863, -0.238856),
	Vector3(-0.951056,  0.162460, -0.262866),
	Vector3(-0.809017,  0.309017, -0.500000),
	Vector3(-0.864188, -0.442863, -0.238856),
	Vector3(-0.951056, -0.162460, -0.262866),
	Vector3(-0.809017, -0.309017, -0.500000),
	Vector3(-0.681718,  0.147621, -0.716567),
	Vector3(-0.681718, -0.147621, -0.716567),
	Vector3(-0.850651,  0.000000, -0.525731),
	Vector3(-0.688191,  0.587785, -0.425325),
	Vector3(-0.587785,  0.425325, -0.688191),
	Vector3(-0.425325,  0.688191, -0.587785),
	Vector3(-0.425325, -0.688191, -0.587785),
	Vector3(-0.587785, -0.425325, -0.688191),
	Vector3(-0.688191, -0.587785, -0.425325)
};

uint8_t QuakeNormal(const Vector3& n)
{
	uint8_t bestIndex = 0;
	float bestDot = -1;

	for (size_t i = 0; i < normals.size(); ++i)
	{
		const float dot = n.DotProduct(normals[i]);
		if (dot > bestDot)
		{
			bestDot = dot;
			bestIndex = i;
		}
	}

	return bestIndex;
}
