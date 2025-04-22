#include <Entity.h>

const bool Entity::isDead() const {
	return isdead;
}

void Entity::UpdateAge() {
	age++;
}

const int Entity::GetAge() const {
	return age;
}

void Entity::killEntity() {
	isdead = true;
}