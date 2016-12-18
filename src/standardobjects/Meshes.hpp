#pragma once

#include <vector>

#include "../Mesh.hpp"

namespace standardobjects{
  class MeshCube : public Mesh{
  public:
    MeshCube() : Mesh(){
      std::vector<int> attributes = {4,4};
      setAttributeSizes(attributes);
      
      float vboData[] = {
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
     setVboData(vboData, sizeof(float) * 32 * 6);
     
     unsigned short iboData[] = {
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
      setIboData(iboData, sizeof(unsigned short) * 36);
      
      setDrawMode(GL_TRIANGLES);
      setNumElements(36);
    }
  };
  
  class MeshTestTriangle : public Mesh{
  public:
    MeshTestTriangle() : Mesh(){
      std::vector<int> att = {4,4};
      setAttributeSizes(att);
      
      float vboData[] = {0.5,0  ,0.5,1,1,0,0,1,
			  0  ,0.5,0.5,1,0,1,0,1,
			  0.5,0.5,0  ,1,0,0,1,1};
      setVboData(vboData, sizeof(float) * 24);
      
      unsigned short iboData[] = {0,1,2};
      setIboData(iboData, sizeof(unsigned short) * 3);
      
      setDrawMode(GL_TRIANGLES);
      setNumElements(3);
    }
  };
}
