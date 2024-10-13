#include "ComputerScienceBuilding.h"
#include <iostream>

// Constructor
ComputerScienceBuilding::ComputerScienceBuilding(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color)
    : AcademicBuilding("Computer Science Building", size, position, color) {

    if (!texture.loadFromFile("assets/cs_building.jpg")) {  // Load specific texture for CS Building
        std::cerr << "Error: Could not load Computer Science Building texture." << std::endl;
    }

    shape.setTexture(&texture); // Set texture for the CS building shape
}

// Implement enter_building
void ComputerScienceBuilding::enter_building(Student& student) {
    reduce_social_battery(student);
    ask_cs_question(student);
}

// Implement ask_cs_question
void ComputerScienceBuilding::ask_cs_question(Student& student) {
    int level = student.get_level();
    std::vector<Question> cs_questions = create_cs_questions();
    
    if (level > 0 && level <= cs_questions.size()) {
        Question& question = cs_questions[level - 1];

        // Display the question and options
        std::cout << "Answering question: " << question.get_text() << "\n";
        const std::vector<std::string>& options = question.get_options();
        for (int i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ": " << options[i] << "\n";
        }

        // Ask for player's answer
        int player_choice = -1;
        std::cout << "Please select an option (1-" << options.size() << "): ";
        std::cin >> player_choice;

        // Validate the input
        while (player_choice < 1 || player_choice > options.size()) {
            std::cout << "Invalid option. Please select a valid option (1-" << options.size() << "): ";
            std::cin >> player_choice;
        }

        // Call answer_question with question and player_choice
        student.answer_question(question, player_choice - 1);  // Adjust index for 0-based choice
    } else {
        std::cout << "No more questions for this level.\n";
    }
}

// Implement create_cs_questions
std::vector<Question> ComputerScienceBuilding::create_cs_questions() {
    std::vector<Question> questions;
    questions.emplace_back(
        "What is OOP?",  // Question text
        std::vector<std::string>{"Object-Oriented Programming", "Functional Programming", "Procedural Programming", "Logic Programming"},  // Options
        0,  // Correct answer index
        2.5  // Difficulty
    );
    questions.emplace_back(
        "What is a virtual function?",
        std::vector<std::string>{"A function that can be overridden", "A function that is always static", "A function that cannot be inherited", "A function that runs outside the program"},
        0,  // Correct answer index
        3.0  // Difficulty
    );
    return questions;
}

// Implement reduce_social_battery
void ComputerScienceBuilding::reduce_social_battery(Student& student) {
    student.get_social_battery().reduce_battery(15);  // Reduce social battery by 15
}