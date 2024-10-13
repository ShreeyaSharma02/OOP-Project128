#include "Student.h"
#include "Building.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Constructor
Student::Student(const std::string& student_name)
    : name(student_name), level(1), grades(0.0), moveSpeed(0.5f), inBuilding(false),
      correct_answers(0), incorrect_answers(0) {  // Initialize counters

    // Load the student texture
    if (!texture.loadFromFile("assets/student.jpg")) {
        std::cerr << "Error: Could not load student texture." << std::endl;
    }

    shape.setSize(sf::Vector2f(50.0f, 50.0f));  // Adjust the student size for better scaling
    shape.setTexture(&texture);  // Apply texture to the student shape
    shape.setPosition(375.0f, 275.0f);  // Initial position
}

// Implement get_grades()
double Student::get_grades() const {
    return grades;
}

// Implement increase_level
void Student::increase_level() {
    level++;  // Increment student's level
    std::cout << "Level increased to: " << level << std::endl;
}

// Implement get_level()
int Student::get_level() const {
    return level;
}

// Implement incrementing correct and incorrect answers
void Student::increment_correct_answers() {
    correct_answers++;
}

void Student::increment_incorrect_answers() {
    incorrect_answers++;
}

int Student::get_correct_answers() const {
    return correct_answers;
}

int Student::get_incorrect_answers() const {
    return incorrect_answers;
}

// Non-const version to allow modification
SocialBattery& Student::get_social_battery() {
    return social_battery;
}

// Const version when no modification is needed
const SocialBattery& Student::get_social_battery() const {
    return social_battery;
}

// Implement increase_grades()
void Student::increase_grades(double amount) {
    grades += amount;

    // Check if the grades have reached level thresholds
    if (grades >= 20 && level < 3) {
        level = 3;
        std::cout << "You've reached level 3! You've won the game!" << std::endl;
    } else if (grades >= 10 && level < 2) {
        level = 2;
        std::cout << "You've reached level 2!" << std::endl;
    }
}

// Implement has_won() to check if the student has won the game
bool Student::has_won() const {
    return level == 3;
}

// Implement visit_building
void Student::visit_building(Building* building) {
    building->enter_building(*this);
}

// Update answer_question to track correct and incorrect answers
void Student::answer_question(Question& question, int player_choice) {
    int correct_index = question.get_correct_option();
    const std::vector<std::string>& options = question.get_options();

    // Check if the player's answer is correct
    if (player_choice == correct_index) {
        std::cout << "Correct answer!\n";
        increment_correct_answers();  // Track correct answer
        increase_grades(5.0);  // Award grades for correct answer
    } else {
        std::cout << "Wrong answer. The correct answer was: " << options[correct_index] << "\n";
        increment_incorrect_answers();  // Track incorrect answer
    }
}

// Implement get_name
const std::string& Student::get_name() const {
    return name;
}

// Getter and setter for inBuilding
bool Student::is_in_building() const {
    return inBuilding;
}

void Student::set_in_building(bool state) {
    inBuilding = state;
}

// Implement movement with boundary checks
void Student::move(const sf::RenderWindow& window) {
    const float stepSize = moveSpeed;  // Use the movement speed for smooth control

    sf::Vector2f position = shape.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (position.y - stepSize > 0) {  // Move up while checking window boundary
            shape.move(0.0f, -stepSize);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (position.y + stepSize + shape.getSize().y < window.getSize().y) {  // Move down while checking boundary
            shape.move(0.0f, stepSize);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (position.x - stepSize > 0) {  // Move left while checking boundary
            shape.move(-stepSize, 0.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (position.x + stepSize + shape.getSize().x < window.getSize().x) {  // Move right while checking boundary
            shape.move(stepSize, 0.0f);
        }
    }
}

// Implement drawing
void Student::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student Name: " << student.get_name() << "\n";
    os << "Level: " << student.get_level() << "\n";
    os << "Grades: " << student.get_grades() << "\n";
    os << "Social Battery: " << student.get_social_battery().get_current_battery() << "\n";
    os << "Correct Answers: " << student.get_correct_answers() << "\n";
    os << "Incorrect Answers: " << student.get_incorrect_answers() << "\n";
    return os;
}

// Implement getShape
const sf::RectangleShape& Student::getShape() const {
    return shape;
}