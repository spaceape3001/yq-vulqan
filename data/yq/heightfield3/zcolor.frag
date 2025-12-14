////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//  This fragment shader produces a simple solid black.

#version 450

#include "heightfield.glsl"

layout(location = 0) out vec4 outColor;
layout(location = 2) in float inZ;

void main() {

    
    //float w = 0.25*inZ; 
    float w = (inZ - u.cmOffset) * u.cmScale;
    outColor = texture(zColor, w);
}
