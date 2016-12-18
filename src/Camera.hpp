#pragma once

#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "Program.hpp"

class Camera{
  
private:
  
  glm::vec3 _position;
  glm::mat4 _orientation;
  
  
public:
  
  Camera();
  Camera(glm::vec3 position, glm::mat4 orientation);
  void setPosition(glm::vec3 position){_position = position;}
  glm::vec3 getPosition(){return _position;}
  void setOrientation(glm::mat4 orientation);
  glm::mat4 getOrientation(){return _orientation;}
  void setCameraTransform(Program *program);
};