#pragma once

#include <Entity.h>
#include <Plants.h>
#include <unordered_map>
#include <typeindex>  // Для std::type_index
#include <typeinfo>   // Для typeid

class World {
private:
    b2World physicsWorld;                     // Мир Box2D
    std::vector<Entity*> entities;            // Все сущности
    sf::RenderWindow& window;                 // Окно SFML   

    // Параметры мира
    float plantRespawnTime = 0.5f;            // Через сколько респавнить растения
    int maxPlants = 100;                      // Максимум растений на карте
    std::unordered_map<std::type_index, int> countEntitys;
public:
    World(sf::RenderWindow& window);
    void update(float deltaTime);             // Обновление логики
    void render();                           // Отрисовка
    void spawnInitialEntities();              // Стартовая генерация
    void spawnPlant(float x, float y);       // Создание растения
    int countEntitys_(std::type_index id);
};