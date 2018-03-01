#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include <vector>

#include <Bengine/Bengine.h>
#include <Bengine/GLSLProgram.h>
#include <Bengine/Sprite.h>
#include <Bengine/GLTexture.h>
#include <Bengine/Window.h>
#include <Bengine/InputManager.h>
#include <Bengine/Timing.h>

#include <Bengine/SpriteBatch.h> 

#include <Bengine/Camera2D.h>

#include "Bullet.h"
#include "player.h"
#include "Sockets.h"
#include <mutex>

enum class GameState2 { PLAY, EXIT };

class BasicGame
{
public:
	BasicGame(socketClient* sockClient);
	~BasicGame();

	void run();                   // to run our game



private:
	void initSystems();           // to initialise opengl and sdl and our game window
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();

	void receiver();

	Bengine::Window  _window;
	int _screenWidth;
	int _screenHeight;
	GameState2 _gameState;


	Bengine::GLSLProgram _colorProgram;
	Bengine::Camera2D _camera;

	Bengine::SpriteBatch _spriteBatch;

	Bengine::InputManager _inputManager;
	Bengine::FpsLimiter _fpsLimiter;

	std::vector<Bullet> _bullets;

	float _maxFPS;
	float _fps;
	float _time;

	socketClient* socket;
	std::string data;
	int m_time;
	std::mutex mtx, timeMtx;
};
