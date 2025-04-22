#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <World.h>

const float SCALE = 30.f; // Масштаб для перевода из метров Box2D в пиксели SFML

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1000, 800 }), "Ecosystem");
    World world(window);  // Создаём мир

    sf::Clock clock;
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        world.update(deltaTime);  // Обновляем логику
        world.render();           // Рендерим
    }
    return 0;
}