
//  Lights
//  When it's a light... alpha doesn't quite matter, instead... fourth will 
//  be intensity, however that gets applied.

struct Light {
    vec3    rgb;
    float   intensity;
    
    //vec3    geo;    // point or plane, depends on the light
    //float   dd;     // either distance or cos cone angle
    //vec3    dir;    // direction of light
    //float   pow;    // corrective power???
    //float   fk, fl, f1, f2; 
};

struct Span {
    uint    begin, end;
};

layout(binding = 0) uniform uniform_t {
    vec4    gamma;
    Span    omni;
    //Span    uni;
    //Span    plane;
    //Span    point;
    //Span    spot;
} u_light;

layout(binding = 0) readonly buffer LightBuffer {
    Light   data[];
} s_light;

//   and light method.... (ignoring ray traching...)

vec3    ambient()
{
    vec3    strength = vec3(0.,0.,0.);
    for(uint n=u_light.omni.begin; n<u_light.omni.end;++n)
        strength    = strength + s_light.data[n].rgb * s_light.data[n].intensity;
    return strength;
}
