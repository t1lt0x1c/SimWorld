#pragma once

#include "Entity.h"
#include "CustomRandom.h"

class Plant : public Entity {
public:
    Plant(b2World& world, float x, float y)
    {
        // Создаём тело в Box2D
        b2BodyDef bodyDef;
        bodyDef.position.Set(x, y);
        bodyDef.type = b2_staticBody;
        body = world.CreateBody(&bodyDef);

        // Круглая форма
        b2CircleShape shape;
        shape.m_radius = 5.0f;

        // Фикстура (можно сделать сенсором)
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.isSensor = true;
        body->CreateFixture(&fixtureDef);

        // Графика
        visual.setRadius(5.0f);          // Радиус в пикселях
        visual.setFillColor(sf::Color::Green);
        visual.setOrigin({ 5.0f, 5.0f });

        max_age = random_int(1200, 1800);
    }

    void update(float deltaTime) override {
        UpdateAge();
        if (GetAge() >= max_age) {
            killEntity();
        }
    }
};