#include "Building.h"
#include <iostream>

// Constructor for Building
Building::Building(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color) 
    : building_name(name) {

    if (!texture.loadFromFile("assets/building.jpg")) {  // Add respective textures for each building
        std::cerr << "Error: Could not load building texture." << std::endl;
    }

    shape.setSize(size);
    shape.setTexture(&texture);  // Apply texture to the building shape
    shape.setPosition(position);
}

// Get building name
std::string Building::get_building_name() const {
    return building_name;
}

// Draw the building using SFML
void Building::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Check collision with the player
bool Building::checkCollision(const Student& student) {
    return shape.getGlobalBounds().intersects(student.getShape().getGlobalBounds());
}
