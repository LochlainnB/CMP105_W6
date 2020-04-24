#include "GravBall.h"

GravBall::GravBall() {
	//set up sprite
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(148, 148));
}

GravBall::~GravBall() {

}

void GravBall::update(float dt) {
	//position and it's derivatives
	setVelocity(getVelocity() + getAcceleration() * getScale() * dt);
	setPosition(getPosition() + getVelocity() * dt);
}

void GravBall::handleInput(float dt) {
	//move to mouse on click
	if (input->isMouseLDown()) {
		setPosition(input->getMouseX(), input->getMouseY());
	}
	//jump
	if (input->isKeyDown(22)) {
		setVelocity(getVelocity() + sf::Vector2f(0, -10 * getScale()));
		input->setKeyUp(22);
	}
}

void GravBall::setScale(float scale) {
	this->scale = scale;
}

float GravBall::getScale() {
	return scale;
}

void GravBall::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void GravBall::setAcceleration(float accelerationX, float accelerationY) {
	this->acceleration = sf::Vector2f(accelerationX, accelerationY);
}

sf::Vector2f GravBall::getAcceleration() {
	return acceleration;
}