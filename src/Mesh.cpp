#include "Mesh.hpp"

Mesh::Mesh(struct MeshData meshData):
_drawMode(GL_TRIANGLES),
_attributeSizes({4}){
	if(meshData.hasCol){
		_attributeSizes.push_back(4);
	}
	if(meshData.hasNormals){
		_attributeSizes.push_back(3);
	}
	
	glGenBuffers(1,&_vbo);
	glGenBuffers(1,&_ibo);
	
	_numElements = meshData.numFaces * 3;

	setVboData(&(meshData.vertexData[0]),
			   sizeof(float) * meshData.vertexData.size());
	setIboData(&(meshData.indexData[0]),
			   sizeof(short unsigned int) * 3 * meshData.numFaces);
}

Mesh::~Mesh(){
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ibo);
  
	GLenum glErr = glGetError();
	if(glErr != GL_NO_ERROR){
		std::cout << "error deleting buffers " << glErr << "\n";
	}
}

void Mesh::setIboData(short unsigned int *indexData, size_t bufferSize){

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, indexData,
				 GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	GLenum glErr = glGetError();
	if(glErr != GL_NO_ERROR){
		std::cout << "error setting IBO data\n";
		throw std::exception();
	}
}

void Mesh::setVboData(float *vertexData, size_t bufferSize){
	if(_attributeSizes.empty() == true){
		std::cout << "attributes must be set to set VBO data\n";
		throw std::exception();
	}
	
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, vertexData, GL_STATIC_DRAW);
  
	int vertexSize = 0;//measured in floats
	for(int i = 0; i < _attributeSizes.size(); i++){
		vertexSize += _attributeSizes.at(i);
	}
	vertexSize *= sizeof(float);
	int currentOffset = 0;
	for(int i = 0; i < _attributeSizes.size(); i++){
		glVertexAttribPointer(i, _attributeSizes.at(i), GL_FLOAT, GL_FALSE,
			  vertexSize, (void*)(sizeof(float) * currentOffset));
		glEnableVertexAttribArray(i);
		currentOffset += _attributeSizes.at(i);
	}
	glBindBuffer(GL_ARRAY_BUFFER, 0);
  
	GLenum glErr = glGetError();
	if(glErr != GL_NO_ERROR){
		std::cout << "error setting VBO data" << glErr << "\n";
		throw std::exception();
	}
}
