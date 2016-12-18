#version 330

layout(location = 0) in vec4 pos;

out vec4 ex_Color;

uniform mat4 worldMatrix;
uniform mat4 cameraMatrix;
uniform mat4 perspectiveMatrix;
uniform vec4 col;

void main()
{
  gl_Position = perspectiveMatrix * cameraMatrix * worldMatrix * pos;
  ex_Color = col;
}
