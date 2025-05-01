#include "World.h"

World::World(sf::RenderWindow& window)
    : window(window), physicsWorld(b2Vec2(0, 0)) {
    // Границы мира (необязательно)
    //createWorldBounds(); 
    // Первичная генерация
    spawnInitialEntities();
    spawnAnimal(500, 400);
}

void World::spawnInitialEntities() {
    // Спавн растений
    for (int i = 0; i < 50; ++i) {
        float x = random_int() % 800 + 100;  // Координаты в пикселях
        float y = random_int() % 600 + 100;
        spawnPlant(x, y);
    }
}

void World::spawnPlant(float x, float y) {
    // Переводим пиксели в метры (Box2D)
    float meterX = x / 30.0f;
    float meterY = y / 30.0f;

    Plant* plant = new Plant(physicsWorld, meterX, meterY);
    entities.push_back(plant);
    countEntitys[typeid(plant)]++;
}

void World::spawnAnimal(float x, float y) {
    // Переводим пиксели в метры (Box2D)
    float meterX = x / 30.0f;
    float meterY = y / 30.0f;

    Animal* plant = new Animal(physicsWorld, meterX, meterY);
    entities.push_back(plant);
    countEntitys[typeid(plant)]++;
}

void World::update(float deltaTime) {
    // Обновляем физику
    physicsWorld.Step(deltaTime, 8, 3);

    // Респавн растений
    static float respawnTimer = 0.0f;
    respawnTimer += deltaTime;
    if (respawnTimer >= plantRespawnTime) {
        respawnTimer = 0.0f;
        if (countEntitys_(typeid(Plant)) < maxPlants) {
            spawnPlant(rand() % 800 + 100, random_int() % 600 + 100);
        }
    }

    // Удаление мёртвых сущностей
    auto it = entities.begin();
    while (it != entities.end()) {
        if(!(*it)->isDead()) (*it)->update(deltaTime);
        if ((*it)->isDead()) {
            delete* it;
            it = entities.erase(it);
            countEntitys[typeid(*it)]--;
            break;
        }
        ++it;
    }
}

void World::render() {
    window.clear();
    for (auto entity : entities) {
        entity->render(window);
    }
    window.display();
}

int World::countEntitys_(std::type_index id) {
    return countEntitys[id];
}