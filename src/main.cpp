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
  	MeshData meshData;
	meshData.numFaces = 12;
	meshData.numVertices = 24;
	meshData.vertexData = {
    //front face
    -.5f, -.5f,  .5f, 1, 0,   1, 0, 1,
    -.5f,  .5f,  .5f, 1, 0, 0.5, 0, 1,
     .5f, -.5f,  .5f, 1, 0, 0.5, 0, 1,
     .5f,  .5f,  .5f, 1, 0, 0.2, 0, 1,
    //right face
    .5f, -.5f, -.5f, 1,   1, 0, 0, 1,
    .5f,  .5f, -.5f, 1, 0.5, 0, 0, 1,
    .5f, -.5f,  .5f, 1, 0.5, 0, 0, 1,
    .5f,  .5f,  .5f, 1, 0.2, 0, 0, 1,
    //left face
    -.5f, -.5f, -.5f, 1, 0, 0,   1, 1,
    -.5f,  .5f, -.5f, 1, 0, 0, 0.5, 1,
    -.5f, -.5f,  .5f, 1, 0, 0, 0.5, 1,
    -.5f,  .5f,  .5f, 1, 0, 0, 0.2, 1,
    //top face
    -.5f,  .5f, -.5f, 1, 0,   1,   1, 1,
    -.5f,  .5f,  .5f, 1, 0, 0.5, 0.5, 1,
     .5f,  .5f, -.5f, 1, 0, 0.5, 0.5, 1,
     .5f,  .5f,  .5f, 1, 0, 0.2, 0.2, 1,
    //bottom face
    -.5f, -.5f, -.5f, 1,   1, 0,   1, 1,
    -.5f, -.5f,  .5f, 1, 0.5, 0, 0.5, 1,
     .5f, -.5f, -.5f, 1, 0.5, 0, 0.5, 1,
     .5f, -.5f,  .5f, 1, 0.2, 0, 0.2, 1,
    //back face
    -.5f, -.5f, -.5f, 1,   1,   1, 0, 1,
    -.5f,  .5f, -.5f, 1, 0.5, 0.5, 0, 1,
     .5f, -.5f, -.5f, 1, 0.5, 0.5, 0, 1,
     .5f,  .5f, -.5f, 1, 0.2, 0.2, 0, 1};
	 meshData.indexData = {
	0, 1, 2,
	1, 3, 2,
	6, 5, 4,
	7, 5, 6,
	8, 9,10,
	9,11,10,
	12,14,13,
	14,15,13,
	16,17,18,
	18,17,19,
	22,21,20,
	22,23,21};
	meshData.hasCol = true;
	//Mesh *m = new Mesh(meshData);
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
