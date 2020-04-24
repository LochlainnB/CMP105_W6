#pragma once
#include "Framework/Vector.h"
#include "Framework/GameObject.h"

class LaunchBall : public GameObject {
public:
	LaunchBall();
	~LaunchBall();

	void update(float dt);
	void handleInput(float dt) override;
	void setScale(float scale);
	float getScale();
	void setAcceleration(sf::Vector2f acceleration);
	void setAcceleration(float accelerationX, float accelerationY);
	sf::Vector2f getAcceleration();
	void setWindow(sf::RenderWindow* window);

protected:
	sf::Vector2f acceleration;
	float scale;
	sf::Texture texture;
	sf::RenderWindow* window;
	bool buttonPressed;
	bool launched;
	sf::Vector2f loc;
};