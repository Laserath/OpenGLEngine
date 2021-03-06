#version 330

in vec2 texCoord0;

uniform vec3 color;
uniform sampler2D sampler;

out vec4 fragColor;

void main() {
    fragColor = texture2D(sampler, texCoord0.xy) * vec4(color, 1.0);
}
