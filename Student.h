#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SocialBattery.h"
#include "Questions.h"

class Student {
private:
    std::string name;
    int level;
    double grades;
    SocialBattery social_battery;
    int correct_answers;  // Track number of correct answers
    int incorrect_answers;  // Track number of incorrect answers
    sf::RectangleShape shape;  // SFML rendering
    float moveSpeed;  // Movement speed for the student
    bool inBuilding;  // Track if the student is inside a building

    sf::Texture texture;  // Manages the student's texture

public:
    Student(const std::string& name);

    // Movement and rendering
    void move(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    // Methods to control the inBuilding state
    bool is_in_building() const;
    void set_in_building(bool state);

    // Leveling system
    void increase_level();  

    // Grades system
    void increase_grades(double amount);

    // Getters and logic for answering questions
    int get_level() const;
    double get_grades() const;
    void answer_question(Question& question, int player_choice);// Update to track correct/wrong answers 
    void visit_building(class Building* building);
    const std::string& get_name() const;

    // Track correct and incorrect answers
    void increment_correct_answers();
    void increment_incorrect_answers();
    int get_correct_answers() const;
    int get_incorrect_answers() const;

    // Other methods
    bool has_won() const;  // Add this method to check if the student has reached the final level

    // Getter for when no modification is needed (const version)
    const SocialBattery& get_social_battery() const;

    // Getter for when modification is needed (non-const version)
    SocialBattery& get_social_battery();

    const sf::RectangleShape& getShape() const;  // For collision detection

    // Overloaded stream operator
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif 