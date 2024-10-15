#include "HUD.h"
#include <iostream> 

HUD::HUD() {
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cerr << "Error: Could not load font." << std::endl;
    } else {
        hudText.setFont(font);
        hudText.setCharacterSize(24);
        hudText.setFillColor(sf::Color::White);
        hudText.setPosition(10.0f, 10.0f);  // Position HUD text
    }
}

void HUD::update(const Student& student) {
    // Remove console output for HUD updates
    // Update HUD with player stats
    hudText.setString(
        "Name: " + student.get_name() +
        "\nLevel: " + std::to_string(student.get_level()) +
        "\nGrades: " + std::to_string(student.get_grades()) +
        "\nSocial Battery: " + std::to_string(student.get_social_battery().get_current_battery()) + "%"
    );
}

void HUD::draw(sf::RenderWindow& window) {
    // Draw HUD text to the window
    window.draw(hudText);
}
