#pragma once

#include "Materials.hpp"
#include "Meshes.hpp"
#include "../RenderableObject.hpp"

namespace standardobjects{
  class ObjTestTriangle : public RenderableObject{
  public:
    ObjTestTriangle() : RenderableObject(){
      setMesh(new MeshTestTriangle);
      setMaterial(new MatPassthroughCol);
    }
  
    ~ObjTestTriangle(){
      delete _mesh;
      delete _material;
    }
  };
  
  class ObjTestCube : public RenderableObject{
  public:
    ObjTestCube() : RenderableObject(){
      setMesh(new MeshCube);
      setMaterial(new MatProjCol);
      glm::vec3 pos(-2.5,-2.5,-20);
      setPosition(pos);
      setOrientation(glm::rotate(getOrientation(), (float)(M_PI/6), glm::vec3(1.0f, 0.0f ,0.0f)));
    }
    
    ~ObjTestCube(){
      delete _mesh;
      delete _material;
    }
  };
}
