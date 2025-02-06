#version 450

layout(location = 0) in vec3 inPosition;
layout(location = 0) out vec3 outPosition;

layout(push_constant) uniform constants {
    mat4    model;
    mat4    view;
    mat4    projection;
} k;

void main() {
    mat4    view    = k.view;
    // remove translations
    view[3] = vec4(0., 0., 0., 1.);
    
    outPosition = inPosition;
    gl_Position = k.projection * view * vec4(inPosition, 1.0);
}

