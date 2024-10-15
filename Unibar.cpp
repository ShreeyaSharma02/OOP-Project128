#include "UniBar.h"
#include <iostream>

UniBar::UniBar(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color)
    : Building("Uni Bar", size, position, color) {

    if (!texture.loadFromFile("assets/unibar.jpg")) {  // Load specific texture for UniBar
        std::cerr << "Error: Could not load UniBar texture." << std::endl;
    }

    shape.setTexture(&texture); // Set texture for the UniBar shape
}

// Implement enter building
void UniBar::enter_building(Student& student) {
    recharge(student);
}

// Implement recharge
void UniBar::recharge(Student& student) {
    student.get_social_battery().recharge_battery(); 
}