#pragma once

#include <vector>
#include <exception>
#include <iostream>

#include <GL/glew.h>

//contains all the data required to make a Mesh class
struct MeshData{
	int numFaces;
	int numVertices;
	std::vector<float> vertexData;
	std::vector<short unsigned int> indexData;
	bool hasNormals = false;
	bool hasCol = false;
};

//contains all the data required to actually draw the 
struct DrawData{
	GLuint vbo;
	GLuint ibo;
	GLenum drawMode;
	int numElements;
};

class Mesh{
    
private:
  
	GLuint _vbo;
	GLuint _ibo;
	GLenum _drawMode;
	int _numElements;
	std::vector<int> _attributeSizes;//in order, measured in floats
    
	void setVboData(float *vertexData, size_t buffersize);
	void setIboData(short unsigned int *indexData, size_t bufferSize);
  
public:
    
	Mesh(struct MeshData meshData);
	~Mesh();
	struct DrawData getDrawData(){return {_vbo,_ibo,_drawMode,_numElements};}
};
