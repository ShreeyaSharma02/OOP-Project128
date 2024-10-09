#include "Student.h"
#include "Questions.h"
#include "Building.h"
#include <iostream>

Student::Student(const std::string& name)
    : name(name), level(1), grades(0.0), social_battery() {}

void Student::answer_question(Question& question) {
    std::cout << question.get_question() << "\n";

    // Display options
    for (size_t i = 0; i < question.get_options().size(); ++i) {
        std::cout << (i + 1) << ") " << question.get_options()[i] << "\n";
    }

    std::cout << "Your Answer (1-" << question.get_options().size() << "): ";

    // Get user input as an integer
    int answer_index;
    std::cin >> answer_index;

    // Validate input
    if (answer_index < 1 || answer_index > static_cast<int>(question.get_options().size())) {
        std::cout << "Invalid input. Please enter a number between 1 and " << question.get_options().size() << ".\n";
        return; // Exit the function on invalid input
    }

    // Check if the answer is correct
    if (question.check_answer(answer_index - 1)) { // Subtract 1 for 0-based index
        std::cout << "Correct!\n";
        grades += 10 * question.get_difficulty();
        add_to_history("Answered correctly: " + question.get_question());
    } else {
        std::cout << "Incorrect. The correct answer was: " << question.get_correct_answer() << "\n";
        grades -= 5;
        add_to_history("Answered incorrectly: " + question.get_question());
    }

    level_up(); // Call to update the level
}

// Additional methods can be implemented below
