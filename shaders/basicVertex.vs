#version 330

layout (location = 0) in vec3 position;
out vec4 color;

uniform mat4 trans;

void main() {
    color = vec4(clamp(position, 0.2, 0.8), 1.0);
    //color = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = trans * vec4(.95 * position, 1.0);
    //gl_Position = vec4(.95 * position, 1.0);
}
