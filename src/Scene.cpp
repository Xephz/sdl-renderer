#include "Scene.hpp"

Scene::Scene(){
}

Scene::~Scene(){
}

void Scene::translateCamera(glm::vec3 relativeTranslation){
    //perform the translation in the basis of the camera orientation
    glm::vec4 absoluteTranslation = 
        glm::inverse(_camera.getOrientation()) * //change of basis
        glm::vec4(relativeTranslation,0);
  _camera.setPosition(_camera.getPosition() + (glm::vec3)absoluteTranslation);
}

void Scene::rotateCamera(glm::mat4 rotation){
  _camera.setOrientation(rotation * _camera.getOrientation());
}

void Scene::addObject(RenderableObject *object){
  _objects.push_back(object);
}

void Scene::renderScene(){
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i=0 ; i < _objects.size(); i++){
    _camera.setCameraTransform(_objects.at(i)->getMaterial()->getProgram());
    _objects.at(i)->renderObject();
  }
  _drawWindow->swapBuffers();
}
