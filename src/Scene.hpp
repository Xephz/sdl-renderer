#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "Camera.hpp"
#include "RenderableObject.hpp"
#include "Window.hpp"

class Scene{
  
private:
  
  Camera _camera;
  std::vector<RenderableObject*> _objects;
  Window *_drawWindow;
  
public:
  
  Scene();
  ~Scene();
  void translateCamera(glm::vec3 relativeTranlation);
  void rotateCamera(glm::mat4 rotation);
  void setDrawWindow(Window *drawWindow){_drawWindow = drawWindow;}
  void addObject(RenderableObject *object);
  void renderScene();
};
