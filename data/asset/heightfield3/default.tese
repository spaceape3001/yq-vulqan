////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#version 450

layout(quads, equal_spacing, ccw) in;

layout(location = 0) in vec2 inPosition[];

layout(push_constant) uniform constants {
    mat4    model2screen;
} k;

vec2  qmix(vec2 a1, vec2 a2, vec2 b1, vec2 b2, float f, float g)
{
    return 
        (1.-f)*(1.-g)*a1 + (1.-f)* g * a2 + f * (1.-g) * b1 + f * g * b2;
}

vec2  qmix(vec2 a1, vec2 a2, vec2 b1, vec2 b2, vec2 fg)
{
    return 
        (1.-fg.x)*(1.-fg.y)*a1 + (1.-fg.x)* fg.y * a2 + fg.x * (1.-fg.y) * b1 + fg.x * fg.y * b2;
}

void main()
{
    vec2    p   = qmix(inPosition[0], inPosition[1], inPosition[2], inPosition[3], gl_TessCoord.x, gl_TessCoord.y);
    gl_Position = k.model2screen * vec4(p.x,p.y,0.,1.);
}
