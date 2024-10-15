#include "Interaction.h"
#include "MathsBuilding.h"
#include "ComputerScienceBuilding.h"
#include "UniBar.h"
#include "MainHub.h"
#include <iostream>
#include <limits>
#include <SFML/Graphics.hpp>


Interaction::Interaction()
    : game_state(false), student(nullptr) {

    // Load the background map texture
    if (!backgroundTexture.loadFromFile("assets/building.jpg")) {
        std::cerr << "Error: Could not load background texture." << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(800.0f / backgroundTexture.getSize().x, 600.0f / backgroundTexture.getSize().y);  // Scale to window size
}

Interaction::~Interaction() {
    delete student;
    for (auto building : buildings) {
        delete building;
    }
}

void Interaction::start_game() {
    game_state = true;
    std::string name;
    std::cout << "Enter your student name: ";
    std::getline(std::cin, name);
    student = new Student(name);

    // Initialize buildings and load textures & Positioning each building on one of the four sides
    buildings.push_back(new MathsBuilding(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(20.0f, 240.0f), sf::Color::Blue)); // Left side
    buildings.push_back(new ComputerScienceBuilding(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(690.0f, 240.0f), sf::Color::Red)); // Right side
    buildings.push_back(new UniBar(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(355.0f, 500.0f), sf::Color::Green)); // Bottom side
    buildings.push_back(new MainHub(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(345.0f, 10.0f), sf::Color::Yellow)); // Top side

    std::cout << "Welcome to the University Simulation Game, " << name << "!\n";
    std::cout << "Buildings initialized. Use WASD to move the student around.\n";
}

void Interaction::manage_interaction(sf::RenderWindow& window) {
    bool isColliding = false;

    while (game_state && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            //Break the loop by closing the window
            if (event.type == sf::Event::Closed) {
                window.close(); 
            }

            // keypresses like Escape to quit the game
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    end_game();
                    return;
                }
            }
        }

        // Check if the student has won 
        if (student->has_won()) {
            show_win_menu(window);
            return;
        }

        // Update player movement
        student->move(window);

        // Check collisions and interactions
        isColliding = false;
        for (Building* building : buildings) {
            if (building->checkCollision(*student)) {
                if (!student->is_in_building()) {
                    std::cout << "Collision detected with " << building->get_building_name() << "\n";
                    building->enter_building(*student);
                    student->set_in_building(true); // Mark student as inside the building
                }
                isColliding = true;
                break;
            }
        }

        // If not colliding with any building, reset the in-building flag
        if (!isColliding) {
            student->set_in_building(false);
        }

        // Update the HUD with student information
        hud.update(*student);

        // Render the game objects
        window.clear(sf::Color::Black);

        // Draw the background 
        window.draw(backgroundSprite);

        // Draw student and buildings
        student->draw(window);
        for (Building* building : buildings) {
            building->draw(window);
        }

        // Draw the HUD
        hud.draw(window);

        window.display();
    }
}

void Interaction::end_game() {
    game_state = false;
    std::cout << "Thank you for playing the University Simulation Game!\n";
}

// Implement the game-winning menu
void Interaction::show_win_menu(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return;
    }

    sf::Text winText;
    winText.setFont(font);
    winText.setString("Congratulations! You've won the game!\n1. Restart Game\n2. Exit");
    winText.setCharacterSize(24);
    winText.setFillColor(sf::Color::White);
    winText.setPosition(200.0f, 250.0f);

    window.clear();
    window.draw(winText);
    window.display();

    // Wait for user input 
    bool selecting = true;
    while (selecting && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1) {
                    // Restart game
                    start_game();
                    selecting = false;
                } else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Escape) {
                    // Close game
                    window.close();
                    selecting = false;
                }
            }
        }
    }
}