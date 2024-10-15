#include <SFML/Graphics.hpp>
#include "Interaction.h"
#include <iostream>

// display welcome window and menu
int display_menu(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return 2; // Exit for font if not found
    }

    sf::Text welcomeText;
    welcomeText.setFont(font);
    welcomeText.setString("Welcome to the University Simulation Game!\n1. Start Game\n2. Exit");
    welcomeText.setCharacterSize(24);
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setPosition(100.0f, 250.0f);

    window.clear();
    window.draw(welcomeText);
    window.display();

    // Handle user input for the menu
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return 2; // Exit game 
            }

            // Check if a key is pressed
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    return 1; // Start the game
                } else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Escape) {
                    return 2; // Exit the game
                }
            }
        }
    }
    return 2; // Default exit 
}

int main() {
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(800, 600), "University Simulation Game");

    // Display welcome screen and menu
    int menu_selection = display_menu(window);

    // Handle menu selection
    if (menu_selection == 2) {
        std::cout << "Exiting game..." << std::endl;
        window.close();
        return 0;
    }

    // Start the game if the user selects "Start Game"
    Interaction interaction;
    interaction.start_game();

    // Main game loop
    while (window.isOpen()) {
        interaction.manage_interaction(window);
    }

    return 0;
}