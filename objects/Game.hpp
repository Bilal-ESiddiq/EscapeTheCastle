#pragma once
#include"GameObject.hpp"
#include"Level.hpp"
using namespace std;
class Game
{
	GLuint programID;
	GLuint MatrixID;
	GLuint TextureID;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
public:
	vector<Level> Levels;
	int level;
	Game();
	void Load();
	void Play();
	void GameOver();
	~Game();
};