#version 330
layout(location = 0) in vec4 in_Position;
layout(location = 1) in vec4 in_Colour;
out vec4 ex_Color;
void main()
{
  gl_Position = in_Position; 
  ex_Color = in_Colour;
}