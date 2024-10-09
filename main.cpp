#include <SFML/Graphics.hpp>
#include "Student.h"
#include "MathsBuilding.h"
#include "ComputerScienceBuilding.h"
#include "UniBar.h"
#include "MainHub.h"
#include "Interaction.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "University Simulation Game");

    Interaction interaction;
    Student student("Player1");

    MathsBuilding mathsBuilding;
    ComputerScienceBuilding csBuilding;
    UniBar uniBar;
    MainHub mainHub;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // Handle other inputs for movement and interactions here
        }

        window.clear();
        // Draw the game elements here
        window.display();
    }

    return 0;
}
