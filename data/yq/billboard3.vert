#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inUV;
layout(location = 0) out vec2 outUV;

layout(push_constant) uniform constants {
    mat4    model;
    mat4    view;
    mat4    projection;
} k;

void main() {
    mat4        vm  = k.view * k.model;
    vm[0][0]    =  0.;
    vm[0][1]    =  1.;
    vm[0][2]    =  0.;
    vm[1][0]    =  0.;
    vm[1][1]    =  0.;
    vm[1][2]    = -1.;
    vm[2][0]    =  0.;
    vm[2][1]    =  0.;
    vm[2][2]    =  1;

    gl_Position = k.projection * vm * vec4(inPosition, 0., 1.0);
    outUV       = inUV;
}

