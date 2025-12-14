////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

layout(vertices=4) out;

#include "heightfield.glsl"

layout(location = 0) in vec2 inUV[];
layout(location = 0) out vec2 outUV[];

void main()
{
    outUV[gl_InvocationID]  = inUV[gl_InvocationID];

    gl_TessLevelOuter[0] = u.oTess[0];
    gl_TessLevelOuter[1] = u.oTess[1];
    gl_TessLevelOuter[2] = u.oTess[2];
    gl_TessLevelOuter[3] = u.oTess[3];
    gl_TessLevelInner[0] = u.iTess[0];
    gl_TessLevelInner[1] = u.iTess[1];
}
