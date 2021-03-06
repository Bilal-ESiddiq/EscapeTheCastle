#include "Game.hpp"



Game::Game()
{
	level = 0;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1920, 1080, "Escape The Castle", glfwGetPrimaryMonitor(), NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1920 / 2, 1080 / 2);

	// Black background
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	programID = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform
	MatrixID = glGetUniformLocation(programID, "MVP");

	TextureID = glGetUniformLocation(programID, "myTextureSampler");

	ViewMatrix = getViewMatrix();
	ProjectionMatrix = getProjectionMatrix();
}

void Game::Load() 
{
	GameObject door("door.obj", "door.bmp");
	GameObject crate("crate.obj", "crate.bmp");
	GameObject btnr("button.obj", "redbutton.bmp");
	GameObject btnb("button.obj", "bluebutton.bmp");
	GameObject btng("button.obj", "greenbutton.bmp");
	GameObject btny("button.obj", "yellowbutton.bmp");
	GameObject key("key.obj", "key.bmp");
	
	Levels[0].Room = new Room("room1.obj", "room1.bmp");
	Levels[0].WorldObjects.push_back(door);
	Levels[0].WorldObjects.push_back(crate);
	Levels[0].WorldObjects.push_back(btnr);

	Levels[1].Room = new Room("room2.obj", "room2.bmp");
	Levels[1].WorldObjects.push_back(door);
	Levels[1].WorldObjects.push_back(btnr);
	Levels[1].WorldObjects.push_back(key);
}

void Game::Play()
{
	
}

void Game::GameOver()
{
}

Game::~Game()
{
}
