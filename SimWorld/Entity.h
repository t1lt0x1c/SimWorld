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
    void render(sf::RenderWindow& window) {
        // Синхронизация позиции с Box2D
        b2Vec2 pos = body->GetPosition();
        visual.setPosition({ pos.x * PIXELS_PER_METER, pos.y * PIXELS_PER_METER });
        window.draw(visual);
    }
    void UpdateAge();
    const int GetAge() const;
    void killEntity();
protected:
    b2Body* body;
    sf::CircleShape visual;
    int max_age;
private:
    int age = 0;
    bool isdead = false;
};