#include "Animal.h"

void Animal::update(float deltatime) {
    //UpdateAge();
    if (isDead()) return;
    //SatietyDown(deltatime * saitety_on_step);
    if (isDead()) return;
}   

double Animal::GetHealth() const {
    return health;
}

double Animal::GetSatiety() const {
    return satiety;
}

void Animal::HealthDown(double h) {
    health -= h;
    if (CheckDead()) {
        killEntity();
    }
}

void Animal::SatietyDown(double h) {    
    satiety -= h;
    if (CheckDead()) {
        killEntity();
    }
}

bool Animal::CheckDead() {
    return GetHealth() <= 0 || GetAge() >= max_age;
}

void Animal::UpdateAge() {
    Entity::UpdateAge();
    if (CheckDead()) {
        killEntity();
    }
}

Animal::Animal(b2World& world, float x, float y)
    {
    float w = 20.0f;
    float h = 10.0f;
    // 1. Создаём физическое тело в Box2D
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;  // Динамическое тело (подвижное)
    bodyDef.position.Set(x, y);     // Позиция в мире Box2D
    body = world.CreateBody(&bodyDef);

    // 2. Создаём форму (капсула = прямоугольник + два полукруга)
    b2PolygonShape box;
    box.SetAsBox(w / 2, h / 2);  // Основная часть "тела"

    b2CircleShape circleFront, circleBack;
    circleFront.m_radius = h / 2;
    circleFront.m_p.Set(w / 2, 0);  // Передний "полукруг"

    circleBack.m_radius = h / 2;
    circleBack.m_p.Set(-w / 2, 0);  // Задний "полукруг"

    // 3. Настраиваем фикстуры
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.0f;      // Плотность
    fixtureDef.friction = 0.3f;     // Трение
    fixtureDef.restitution = 0.1f;  // Упругость

    // Добавляем все части к телу
    fixtureDef.shape = &box;
    body->CreateFixture(&fixtureDef);

    fixtureDef.shape = &circleFront;
    body->CreateFixture(&fixtureDef);

    fixtureDef.shape = &circleBack;
    body->CreateFixture(&fixtureDef);

    // 4. Настраиваем графику SFML (овал)
    visual.setPointCount(20);  // Гладкий овал
    for (int i = 0; i < 20; ++i) {
        float angle = 2 * b2_pi * i / 20;
        visual.setPoint(i, sf::Vector2f(
            w / 2 * std::cos(angle),
            h / 2 * std::sin(angle)
        ));
    }
    visual.setFillColor(sf::Color::Red);
    visual.setOrigin({ w / 2, h / 2 });
}