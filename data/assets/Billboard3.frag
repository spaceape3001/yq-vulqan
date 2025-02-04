#version 450

layout(location = 0) in  vec2 inUV;
layout(location = 0) out vec4 outColor;

layout(push_constant) uniform constants {
    mat4    model;
    mat4    view;
    mat4    projection;
} k;

layout(binding = 0) uniform sampler2D texSampler;

void main() 
{
    outColor = vec4(0.1,2.0,0.1,1.0) * texture(texSampler, inUV);
}
