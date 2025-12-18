#version 450

layout(location = 0) in vec2 inPosition;
layout(location = 1) in vec2 inUV;
layout(location = 0) out vec2 outUV;

layout(push_constant) uniform constants {
    mat4    model2screen;
} k;

void main() {
    gl_Position = k.model2screen * vec4(inPosition, 0., 1.0);
    outUV       = inUV;
}

