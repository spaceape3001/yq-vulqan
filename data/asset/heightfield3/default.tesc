////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

layout(vertices=4) out;

layout(location = 0) in vec2 inPosition[];
layout(location = 0) out vec2 outPosition[];

void main()
{
    outPosition[gl_InvocationID] = inPosition[gl_InvocationID];
    gl_TessLevelOuter[0]    = 2;
    gl_TessLevelOuter[1]    = 2;
    gl_TessLevelOuter[2]    = 2;
    gl_TessLevelOuter[3]    = 2;
    gl_TessLevelInner[0]    = 1.;
    gl_TessLevelInner[1]    = 1.;
}
