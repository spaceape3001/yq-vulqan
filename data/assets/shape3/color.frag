#version 450

layout(binding = 0) uniform uniform_t {
    vec4    color;
} u;

void main() {
    outColor = fragColor;
}


