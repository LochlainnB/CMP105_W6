#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"

class GravBall : public GameObject {
public:
	GravBall();
	~GravBall();

	void update(float dt);
	void handleInput(float dt) override;
	void setScale(float scale);
	float getScale();
	void setAcceleration(sf::Vector2f acceleration);
	void setAcceleration(float accelerationX, float accelerationY);
	sf::Vector2f getAcceleration();

protected:
	sf::Vector2f acceleration;
	float scale;
	sf::Texture texture;
};