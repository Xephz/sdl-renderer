#pragma once

#include <glm/glm.hpp>

#include "Program.hpp"


//contains the data required to generate a materials program from defaults
struct MaterialData{
	bool meshHasNormals = false;
	bool meshHasColour = false;
	//used for a global colour if the mesh has none
	glm::vec4 colour = {1.0f,0.0f,1.0f,1.0f};
};

class Material{
  
private:
  Program *_program;
  
  //defines a perspective projection matrix and associated parameters
  static constexpr float _aspectRatio = 1.777777777777;
  static constexpr float _fov = 60;
  static constexpr float _zNear = 0.5;
  static constexpr float _zFar = 1000;
  glm::mat4 _projMat
   = glm::mat4(1/(tan(((_fov * 2 * M_PI) / 360)/2)), 0, 0, 0,
     0, 1/(tan((((_fov * 2 * M_PI) / 360) / _aspectRatio)/2)), 0, 0,
     0, 0, (_zFar + _zNear) / (_zNear - _zFar), -1,
     0, 0, (2 * _zFar * _zNear) / (_zNear - _zFar), 0);

  
public:
  Material(struct MaterialData materialData);//uses default shaders
  Material();//for custom shaders 
//custom shaders can use uniforms worldMatrix(set by object)
//and viewMatrix(set by camera)
  ~Material();
  Program *getProgram(){return _program;}
};
