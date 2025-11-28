#version 450

layout(location = 0) in vec3 inPosition;

layout(push_constant) uniform constants {
    mat4    model2screen;
} k;

void main() {
    gl_Position = k.model2screen * vec4(inPosition, 1.0);
}

