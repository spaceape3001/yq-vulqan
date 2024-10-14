#version 450 core

//  This file comes from ImGui's vulkan backend
//  It's licensed under ImGui's terms

layout(location = 0) out vec4 fColor;

layout(set=0, binding=0) uniform sampler2D sTexture;

layout(location = 0) in struct {
    vec4 Color;
    vec2 UV;
} In;

void main()
{
    //vec4 v = texture(sTexture, In.UV.st);
    //fColor  = In.Color * v.b;

    fColor = In.Color * texture(sTexture, In.UV.st);
}
