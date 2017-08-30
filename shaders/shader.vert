#version 330

in vec3 position;

out vec3 colour;

uniform vec3 inColour;
uniform mat4 transformation;
uniform mat4 projection;

void main() {
  gl_Position = transformation * vec4(position, 1.0);
  
  colour = inColour;
}
