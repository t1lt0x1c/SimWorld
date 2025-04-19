#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SimWorld");

    while (window.isOpen()) {
        // Объявляем объект события
        sf::Event event();
        // Обрабатываем события
        while (window.pollEvent()) {
            // Проверяем тип события через метод type()
            if (event.type() == sf::Event::Type::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}