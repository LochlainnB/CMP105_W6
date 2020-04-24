#include "FollowBall.h"

FollowBall::FollowBall() {
	//set up sprite
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(148, 148));
}

FollowBall::~FollowBall() {

}

void FollowBall::update(float dt) {
	//position and it's derivatives
	setVelocity(getVelocity() + getAcceleration() * getScale() * dt);
	setPosition(getPosition() + getVelocity() * dt);
}

void FollowBall::handleInput(float dt) {
	//move to cursor
	sf::Vector2f direction = sf::Vector2f(input->getMouseX(), input->getMouseY()) - getPosition();
	setVelocity(sqrt(Vector::magnitude(getVelocity())) * Vector::normalise(direction));
	setAcceleration(sqrt(Vector::magnitude(getAcceleration())) * Vector::normalise(direction));
	//reset game
	if (Vector::magnitude(direction) < 400) {
		setVelocity(0, 0);
	}
}

void FollowBall::setScale(float scale) {
	this->scale = scale;
}

float FollowBall::getScale() {
	return scale;
}

void FollowBall::setAcceleration(sf::Vector2f acceleration) {
	this->acceleration = acceleration;
}

void FollowBall::setAcceleration(float accelerationX, float accelerationY) {
	this->acceleration = sf::Vector2f(accelerationX, accelerationY);
}

sf::Vector2f FollowBall::getAcceleration() {
	return acceleration;
}