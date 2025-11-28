#version 450

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform uniform_t {
    vec4    color;
} u;

void main() {
    outColor = u.color;
}


