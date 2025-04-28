#include "Animal.h"

void Animal::update(float deltatime) {
    UpdateAge();
    if (isDead()) return;
    SatietyDown(deltatime * saitety_on_step);
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