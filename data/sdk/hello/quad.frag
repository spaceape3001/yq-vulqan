#version 450

layout(location = 0) in  vec2 inUV;
layout(location = 0) out vec4 outColor;

 layout(binding = 0) uniform sampler2D texSampler;


void main() 
{
    //outColor    = vec4(1.-inUV.x, 0.+inUV.y, 0., 0);
    outColor = texture(texSampler, inUV);
}
