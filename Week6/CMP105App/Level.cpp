#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	gravBall.setInput(input);
	gravBall.setPosition(100, 100);
	gravBall.setAcceleration(0, 9.8);
	gravBall.setScale(50);

	followBall.setInput(input);
	followBall.setPosition(300, 100);
	followBall.setAcceleration(0, 1);
	followBall.setScale(50);

	launchBall.setInput(input);
	launchBall.setWindow(window);
	launchBall.setPosition(500, 100);
	launchBall.setAcceleration(0, 9.8);
	launchBall.setScale(50);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	gravBall.handleInput(dt);
	followBall.handleInput(dt);
	launchBall.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	gravBall.update(dt);
	followBall.update(dt);
	launchBall.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(gravBall);
	window->draw(followBall);
	window->draw(launchBall);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}