#include "Material.hpp"

Material::Material(struct MaterialData materialData):
  _program(new Program()){
	if(!materialData.meshHasColour &&
		!materialData.meshHasNormals){
      _program -> pushShader("assets/shaders/NoLightNoColVert.glsl", GL_VERTEX_SHADER);
      _program -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      _program -> link();
	  _program -> updateUniform("perspectiveMatrix", _projMat);
	  _program -> updateUniform("col", materialData.colour);
	}
	if(materialData.meshHasColour &&
		!materialData.meshHasNormals){
      _program -> pushShader("assets/shaders/NoLightVert.glsl", GL_VERTEX_SHADER);
      _program -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      _program -> link();
	  _program -> updateUniform("perspectiveMatrix", _projMat);
	}
	if(!materialData.meshHasColour &&
		materialData.meshHasNormals){
        printf("aaa\n\n");
      _program -> pushShader("assets/shaders/DiffLightNoColVert.glsl", GL_VERTEX_SHADER);
      _program -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      _program -> link();
	  _program -> updateUniform("perspectiveMatrix", _projMat);
	  _program -> updateUniform("col", materialData.colour);
	}
	if(materialData.meshHasColour &&
		materialData.meshHasNormals){
      _program -> pushShader("assets/shaders/DiffLightVert.glsl", GL_VERTEX_SHADER);
      _program -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      _program -> link();
	  _program -> updateUniform("perspectiveMatrix", _projMat);
	}
	
}

Material::Material():
  _program(new Program()){
}

Material::~Material(){
  delete _program;
}
