#version 450

layout(binding = 0) uniform uniform_t {
    vec4    color;
} u;

layout(location = 0) out vec4 outColor;

void main() {
    outColor = u.color;
}


