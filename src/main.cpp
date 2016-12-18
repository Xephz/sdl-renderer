#include <typeinfo>
#include <vector>

#include <glm/glm.hpp>
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "AssimpLoader.hpp"
#include "Material.hpp"
#include "Mesh.hpp"
#include "InputHandler.hpp"
#include "Scene.hpp"
#include "standardobjects/InputHandlers.hpp"
#include "Window.hpp"

int main(int argc, char *argv[]){
  Window *w = new Window;

  Scene *s = new Scene;
  s->setDrawWindow(w);
  s->translateCamera(glm::vec3(1.0f,0.0f,-6.0f));
  
	AssimpLoader *a = new AssimpLoader("assets/sampleMeshes/cube.obj");

    Mesh *m = a->makeMesh();
	Material *mat = a->makeMaterial();
	RenderableObject *o = new RenderableObject(mat, m);
	s->addObject(o);
  
	standardobjects::CameraController *i = new standardobjects::CameraController;
  
	while(!i->quit()){
		SDL_Delay(1);
		i->handleInput(s);
		s->renderScene();
	}
  
	delete i;
	delete o;
	delete a;
	delete mat;
	delete m;
	delete w;
	delete s;
	return 0;
}
