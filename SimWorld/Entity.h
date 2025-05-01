#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>



const float PIXELS_PER_METER = 30.0f;

class Entity {
public:
    virtual ~Entity() = default;
    const bool isDead() const;
    // Обновление логики (вызывается каждый кадр)
    virtual void update(float deltaTime) = 0;

    // Отрисовка (вызывается каждый кадр)
    virtual void render(sf::RenderWindow& window) = 0;
    void UpdateAge();
    const int GetAge() const;
    void killEntity();
protected:
    b2Body* body;
    int max_age;
private:
    int age = 0;
    bool isdead = false;
};