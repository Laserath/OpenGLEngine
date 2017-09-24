#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

out vec2 texCoord0;
out vec3 normal0;
out vec3 worldPos0;
out vec4 normalColor;

uniform mat4 transform;
uniform mat4 transformProjected;

vec3 getNormalColor(vec3 normal) {
    vec3 normColor = vec3(0,0,0);
    if (normal.x == 1) {
        normColor.x = 1;
    } else if (normal.x == 0) {
        normColor.x = .5;
    } else if (normal.x == -1) {
        normColor.x = 0;
    }

    if (normal.y == 1) {
        normColor.y = 1;
    } else if (normal.y == 0) {
        normColor.y = .5;
    } else if (normal.y == -1) {
        normColor.y = 0;
    }

    if (normal.z == 1) {
        normColor.z = 1;
    } else if (normal.z == 0) {
        normColor.z = .5;
    } else if (normal.z == -1) {
        normColor.z = 0;
    }
    return normColor;
}

void main() {
    gl_Position = transformProjected * vec4(position, 1.0);
    texCoord0 = texCoord;
    normal0 = (transform * vec4(normal, 0.0)).xyz;
    worldPos0 = (transform * vec4(position, 1.0)).xyz;
    normalColor = vec4(getNormalColor(normal), 1.0);
}
