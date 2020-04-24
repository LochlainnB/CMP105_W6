#include "LaunchBall.h"

LaunchBall::LaunchBall() {
	//set up sprite
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(148, 148));
	buttonPressed = false;
	launched = false;
}

LaunchBall::~LaunchBall() {

}

void LaunchBall::update(float dt) {
	//update velocity
	if (launched) {
		setVelocity(getVelocity() + getAcceleration() * getScale() * dt);
		setPosition(getPosition() + getVelocity() * dt);
	}
	//update position
	sf::Vector2f target = getPosition() + getVelocity() * dt;
	//bounce
	if (target.x < 0) {
		target.x = abs(target.x);
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	else if (target.x + getSize().x > window->getSize().x) {
		target.x = 2 * (window->getSize().x - getSize().x) - target.x;
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	if (target.y < 0) {
		target.y = abs(target.y);
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}
	else if (target.y + getSize().y > window->getSize().y) {
		target.y = 2 * (window->getSize().y - getSize().y) - target.y;
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}
}

void LaunchBall::handleInput(float dt) {
	//wait for button press
	if (input->isMouseLDown() && !buttonPressed && !launched) {
		loc = sf::Vector2f(input->getMouseX(), input->getMouseY());
		buttonPressed = true;
	}
	//calculate trajectory and fire
	else if (!input->isMouseLDown() && buttonPressed) {
		setVelocity(loc - sf::Vector2f(input->getMouseX(), input->getMouseY()));
		buttonPressed = false;
		launched = true;
	}
}

void LaunchBall::setScale(float scale) {
	this->scale = scale;
}

float LaunchBall::getScale() {
	return scale;
}

void LaunchBall::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void LaunchBall::setAcceleration(float accelerationX, float accelerationY) {
	this->acceleration = sf::Vector2f(accelerationX, accelerationY);
}

sf::Vector2f LaunchBall::getAcceleration() {
	return acceleration;
}

void LaunchBall::setWindow(sf::RenderWindow* window) {
	this->window = window;
}