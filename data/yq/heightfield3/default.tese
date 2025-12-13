////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

#include <yq/qmix2.glsl>

layout(quads, equal_spacing, ccw) in;

layout(location = 0) in vec2 inPosition[];

layout(push_constant) uniform constants {
    mat4    model2screen;
} k;

void main()
{
    vec2    p   = qmix(inPosition[0], inPosition[1], inPosition[2], inPosition[3], gl_TessCoord.x, gl_TessCoord.y);
    gl_Position = k.model2screen * vec4(p.x,p.y,0.,1.);
}
