#include "Camera.hpp"

Camera::Camera():
_position(glm::vec3(0)),
_orientation(glm::mat4(1.0f)){
}

Camera::Camera(glm::vec3 position, glm::mat4 orientation):
_position(position),
_orientation(orientation){
}

void Camera::setOrientation(glm::mat4 orientation){
  _orientation = orientation;
}

void Camera::setCameraTransform(Program *program){
  glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), _position);
    glm::mat4 cameraMatrix = _orientation * translationMatrix;
  program->updateUniform((std::string)"cameraMatrix", cameraMatrix);
}
