////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/pushfull.glsl>

layout(binding = 2) uniform uniform_t {
    vec4    oTess;
    vec4    rgba;
    vec2    iTess;
    vec2    uvScale;
    vec2    uvOffset;
    float   cmScale;
    float   cmOffset;
} u;

layout(binding = 3) uniform sampler2D heightSampler;
layout(binding = 4) uniform sampler1D zColor;

vec2    uv2xy(vec2 uv)
{
    return 2.*uv - vec2(1.,1.);;
}

vec4    uv2screen(vec2 uv)
{
    vec2 xy = uv2xy(uv);
    return kPush.model2screen * vec4( xy.x, xy.y, 0., 1. );
}

vec4    uv2screen(vec2 uv, float z)
{
    vec2 xy = uv2xy(uv);
    return kPush.model2screen * vec4( xy.x, xy.y, -z, 1. );
}

float uvZ(vec2 uv)
{
    return texture(heightSampler, uv).x;
}

vec4    uv2screenZ(vec2 uv)
{
    return uv2screen(uv, uvZ(uv));
}

