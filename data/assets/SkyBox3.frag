#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 0) out vec4 outColor;
layout(binding = 0) uniform samplerCube texSampler;

void main() 
{
    outColor = (0.75+0.25*vec4(inPosition, 1.)) * texture(texSampler, inPosition);
}
