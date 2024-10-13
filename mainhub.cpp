#include "MainHub.h"
#include <iostream>

// Constructor
MainHub::MainHub(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color)
    : Building("Main Hub", size, position, color) {

    // Load texture for Main Hub
    if (!texture.loadFromFile("assets/mainhub.jpg")) {
        std::cerr << "Error: Could not load Main Hub texture." << std::endl;
    }

    shape.setTexture(&texture);  // Apply texture
}

// Implement the pure virtual function from Building
void MainHub::enter_building(Student& student) {
    std::cout << "Welcome to the Main Hub, " << student.get_name() << "!\n";

    // Example logic for entering the Main Hub
    std::cout << "Here, you can view your stats and review your progress!\n";

    // Call methods to view stats and history
    view_stats(student);
}

// Implement view_stats to display correct/incorrect answers
void MainHub::view_stats(const Student& student) {
    std::cout << "----- Student Stats -----\n";
    std::cout << "Name: " << student.get_name() << "\n";
    std::cout << "Level: " << student.get_level() << "\n";
    std::cout << "Grades: " << student.get_grades() << "\n";
    std::cout << "Social Battery: " << student.get_social_battery().get_current_battery() << "%\n";
    std::cout << "Correct Answers: " << student.get_correct_answers() << "\n";
    std::cout << "Incorrect Answers: " << student.get_incorrect_answers() << "\n";
    std::cout << "-------------------------\n";
}