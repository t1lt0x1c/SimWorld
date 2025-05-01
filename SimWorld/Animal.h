#pragma once
#include "Entity.h"

class Animal : public Entity {
public:
	Animal(b2World& world, float x, float y);

	void update(float deltaTime) override;

	//Здоровье
	double GetHealth() const;
	void HealthUp(double h);
	void HealthDown(double h);

	//Сытость
	double GetSatiety() const;
	void SatietyUp(double s);
	void SatietyDown(double s);

	void UpdateAge();

	void render(sf::RenderWindow& window) override {
		// Синхронизация позиции с Box2D
		b2Vec2 pos = body->GetPosition();
		visual.setPosition({ pos.x * PIXELS_PER_METER, pos.y * PIXELS_PER_METER });
		window.draw(visual);
	}

private:
	double max_health;
	double health;
	double satiety;
	double saitety_on_step;

	sf::ConvexShape visual;
private:
	bool CheckDead();
};