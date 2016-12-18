#include "RenderableObject.hpp"

RenderableObject::RenderableObject():
_position(glm::vec3(0)),
_orientation(glm::mat4(1.0f)){}

RenderableObject::RenderableObject(Material *material, Mesh *mesh):
_material(material),
_mesh(mesh),
_position(glm::vec3(0)),
_orientation(glm::mat4(1.0f)){}

void RenderableObject::renderObject(){
  
  //TODO Check material is all initialized correctly
  
  glUseProgram(_material->getProgram()->getId());
  setWorldTransform();
  
  struct DrawData drawData = _mesh->getDrawData();
  
  //TODO check data is loaded onto GPU
  if(drawData.drawMode == GL_FALSE){
    std::cout << "cannot render with undefined drawmode\n";
    throw std::exception();
  }
  if(drawData.numElements == 0){
    std::cout << "numElements must be positive\n";
    throw std::exception();
  }
  
  glBindBuffer(GL_ARRAY_BUFFER, drawData.vbo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawData.ibo);
  glDrawElements(drawData.drawMode, drawData.numElements,
		 GL_UNSIGNED_SHORT, 0);
}

void RenderableObject::setWorldTransform(){
  glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), _position);
  glm::mat4 worldMatrix = translationMatrix * _orientation;
  _material->getProgram()->updateUniform((std::string)"worldMatrix",worldMatrix);
}
