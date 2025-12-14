////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

layout(quads, equal_spacing, ccw) in;

#include <yq/qmix2.glsl>
#include "heightfield.glsl"
#include "heightmap.glsl"

layout(location = 0) in vec2   inUV[];
layout(location = 1) out vec2  outUV;
layout(location = 2) out float outZ;

void main()
{
    outUV       = qmix(inUV[0], inUV[1], inUV[2], inUV[3], gl_TessCoord.x, gl_TessCoord.y);
    outZ        = uvZ(outUV);
    gl_Position = uv2screen(outUV, outZ);
}
