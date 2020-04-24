#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"

class FollowBall : public GameObject {
public:
	FollowBall();
	~FollowBall();

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