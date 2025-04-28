#pragma once
#include "Entity.h"

class Animal : public Entity {
	Animal(b2World& world, float x, float y);

	void update(float deltaTime) override;

	//Движение
	void MoveForward(double force = 3);
	void Rotation(double rad);

	//Здоровье
	double GetHealth() const;
	void HealthUp(double h);
	void HealthDown(double h);

	//Сытость
	double GetSatiety() const;
	void SatietyUp(double s);
	void SatietyDown(double s);

	void UpdateAge();

private:
	double max_health;
	double health;
	double satiety;
	double saitety_on_step;
private:
	bool CheckDead();
};