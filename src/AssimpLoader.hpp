#pragma once

#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Material.hpp"
#include "Mesh.hpp"

class AssimpLoader{
    
private:
    
	Assimp::Importer *_importer;
    const aiScene *_scene;
    
public:
    
    AssimpLoader(std::string path);
	~AssimpLoader();
    Mesh* makeMesh();
	Material* makeMaterial();
};
