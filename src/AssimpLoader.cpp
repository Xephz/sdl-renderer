#include "AssimpLoader.hpp"

AssimpLoader::AssimpLoader(std::string path):
_importer(new Assimp::Importer){
    _scene = _importer->ReadFile(path,
								 aiProcess_Triangulate |
								 aiProcess_OptimizeMeshes);
}

AssimpLoader::~AssimpLoader(){
	delete _importer;
}

Mesh* AssimpLoader::makeMesh(){
	struct MeshData meshData;
	
	meshData.numFaces = _scene->mMeshes[0]->mNumFaces;
	meshData.numVertices = _scene->mMeshes[0]->mNumVertices;
	meshData.hasNormals = _scene->mMeshes[0]->HasNormals();
	
	for(int i = 0; i < meshData.numVertices; i++){
		//position
		for(int j = 0; j < 3; j++){
			meshData.vertexData.push_back(_scene->mMeshes[0]->mVertices[i][j]);}
			meshData.vertexData.push_back(1);
		
		
		//Colour
		if(_scene->mMeshes[0]->HasVertexColors(0)){
			for(int j = 0; j < 4; j++){
			//	meshData.vertexData.push_back(_scene->mMeshes[0]->mColors[i][j]);
			}
		}
		//Normal
		if(meshData.hasNormals){
			for(int j = 0; j < 3; j++){
				meshData.vertexData.push_back(_scene->mMeshes[0]->mNormals[i][j]);
			}
		}
	}
	
	for(int i = 0; i < meshData.numFaces; i++){
		meshData.indexData.push_back(_scene->mMeshes[0]->mFaces[i].mIndices[0]);
		meshData.indexData.push_back(_scene->mMeshes[0]->mFaces[i].mIndices[1]);
		meshData.indexData.push_back(_scene->mMeshes[0]->mFaces[i].mIndices[2]);
	}
	
	return new Mesh(meshData);
}

Material* AssimpLoader::makeMaterial(){
	struct MaterialData materialData;
	if(_scene->mMeshes[0]->HasNormals()){
		materialData.meshHasNormals = true;
	}
	if(_scene->mMeshes[0]->HasVertexColors(0)){
		materialData.meshHasColour = true;
	}
	return new Material(materialData);
}
