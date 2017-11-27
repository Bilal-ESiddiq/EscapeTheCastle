#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/objloader.hpp>

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing fla
struct coordinates {
	float x,y,z;
};

class GameObject
{
public:
	bool visible;
	string objectName;
	coordinates Translate;
	coordinates Rotate;
	coordinates Scale;
	string Texture;
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	GameObject(string Name, string texName);
	virtual void Draw();
	~GameObject();
};

