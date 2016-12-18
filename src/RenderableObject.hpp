#pragma once

#include <iostream>
#include <exception>

#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "Material.hpp"
#include "Mesh.hpp"

class RenderableObject{

private:
  
  glm::vec3 _position;
  glm::mat4 _orientation;
  
protected:
  
  RenderableObject();
  Material *_material;
  Mesh *_mesh;
  
public:
  
  RenderableObject(Material *material, Mesh *mesh);
  void renderObject();
  void setMaterial(Material *material){_material = material;}
  Material *getMaterial(){return _material;}
  void setMesh(Mesh *mesh){_mesh = mesh;}
  void setPosition(glm::vec3 position){_position = position;}
  void setOrientation(glm::mat4 orientation){_orientation = orientation;}
  glm::mat4 getOrientation(){return _orientation;}
  void setWorldTransform();
};
