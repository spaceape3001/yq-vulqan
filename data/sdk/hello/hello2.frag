#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform UniformBufferObject {
    vec4 dope;
} ubo;

void main() {
    outColor = ubo.dope * vec4(fragColor, 1.0);
}


