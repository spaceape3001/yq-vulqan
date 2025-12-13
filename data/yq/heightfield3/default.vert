////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

layout(location = 0) in vec2 inPosition;
//layout(location = 1) in vec2 inUV;
layout(location = 0) out vec2 outPosition;

layout(push_constant) uniform constants {
    mat4    model2screen;
} k;

//layout(binding = 0) uniform sampler2D heightSampler;

void main() {
    //float z = texture(heightSampler, inUV).x;
    outPosition = inPosition;
    gl_Position = k.model2screen * vec4(inPosition.x, inPosition.y, 0., 1.0);
}

