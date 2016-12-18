#version 330

layout(location = 0) in vec4 pos;
layout(location = 1) in vec4 col;
layout(location = 2) in vec3 normal;

out vec4 ex_Color;

uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 perspectiveMatrix;

void main()
{
  gl_Position = perspectiveMatrix * viewMatrix * worldMatrix * pos;
  
  vec3 lightDir = normalize(vec3(2,1,3));
  vec3 calcdCol = col.xyz * ((0.9 * clamp(dot(normal, lightDir),0,1)) + 0.1);
  ex_Color.xyz = vec4(calcdCol,col.w);
}
