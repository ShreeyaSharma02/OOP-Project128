#include "MathsBuilding.h"
#include <iostream>

// Constructor with SFML integration
MathsBuilding::MathsBuilding(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color)
    : AcademicBuilding("Maths Building", size, position, color) {

    if (!texture.loadFromFile("assets/maths_building.jpg")) {  // Load specific texture for MathsBuilding
        std::cerr << "Error: Could not load Maths Building texture." << std::endl;
    }

    shape.setTexture(&texture); // Set texture for the Maths building shape
}

// Implement enter_building
void MathsBuilding::enter_building(Student& student) {
    reduce_social_battery(student);
    ask_maths_question(student);
}

// Implement ask_maths_question
void MathsBuilding::ask_maths_question(Student& student) {
    int level = student.get_level();
    std::vector<Question> math_questions = create_math_questions();
    
    if (level > 0 && level <= math_questions.size()) {
        Question& question = math_questions[level - 1];
        
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

// Implement create_math_questions
std::vector<Question> MathsBuilding::create_math_questions() {
    std::vector<Question> questions;
    questions.emplace_back(
        "What is 2 + 2?",                           // Question text
        std::vector<std::string>{"3", "4", "5", "6"}, // Options
        1,                                           // Correct answer index
        1.0                                          // Difficulty level
    );
    questions.emplace_back(
        "Solve x: 2x = 10",                         // Question text
        std::vector<std::string>{"4", "5", "6", "7"}, // Options
        1,                                           // Correct answer index
        1.5                                          // Difficulty level
    );
    return questions;
}

// Implement reduce_social_battery
void MathsBuilding::reduce_social_battery(Student& student) {
    student.get_social_battery().reduce_battery(10);  // Reduce social battery by 10
}