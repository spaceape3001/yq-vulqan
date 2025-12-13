////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//  This fragment shader produces a simple solid black.

#version 450

layout(location = 0) out vec4 outColor;

void main() {
    outColor = vec4(1., 1., 0., 1.);
}

#version 450

layout(location = 0) out vec4 outColor;

void main() {
    outColor = vec4(0., 0., 0., 1.);
}

