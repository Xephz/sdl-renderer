#pragma once

#include <string>

#include <math.h>

#include "../Material.hpp"

namespace standardobjects{
  class MatPassthroughCol : public Material{ 
  public:
    MatPassthroughCol() : Material(){
      getProgram() -> pushShader("assets/shaders/PassthroughVert.glsl", GL_VERTEX_SHADER);
      getProgram() -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      getProgram() -> link();
    }
  };
  
  class MatProjCol : public Material{
  public:
    MatProjCol() : Material(){
      getProgram() -> pushShader("assets/shaders/NoLightVert.glsl", GL_VERTEX_SHADER);
      getProgram() -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      getProgram() -> link();
      
      std::string name = "perspectiveMatrix";
      float aspectRatio = 1.777777777777;
      float fov = 60;
      float zNear = 0.5;
      float zFar = 1000;
      float fovx = (fov * 2 * M_PI) / 360;
      float fovy = fovx / aspectRatio;
      glm::mat4 data(1/(tan(fovx/2)), 0, 0, 0,
		     0, 1/(tan(fovy/2)), 0, 0,
		     0, 0, (zFar + zNear) / (zNear - zFar), -1,
		     0, 0, (2 * zFar * zNear) / (zNear - zFar), 0);
      getProgram() -> updateUniform(name, data);
    }
  };
  
  class MatProj : public Material{
  public:
	  MatProj() : Material(){
      getProgram() -> pushShader("assets/shaders/NoLightNoColVert.glsl", GL_VERTEX_SHADER);
      getProgram() -> pushShader("assets/shaders/PassthroughFrag.glsl", GL_FRAGMENT_SHADER);
      getProgram() -> link();
      
      std::string name = "perspectiveMatrix";
      float aspectRatio = 1.777777777777;
      float fov = 60;
      float zNear = 0.5;
      float zFar = 1000;
      float fovx = (fov * 2 * M_PI) / 360;
      float fovy = fovx / aspectRatio;
      glm::mat4 data(1/(tan(fovx/2)), 0, 0, 0,
		     0, 1/(tan(fovy/2)), 0, 0,
		     0, 0, (zFar + zNear) / (zNear - zFar), -1,
		     0, 0, (2 * zFar * zNear) / (zNear - zFar), 0);
      getProgram() -> updateUniform(name, data);
  }
  };
}
