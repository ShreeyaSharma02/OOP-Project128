#include "MathsBuilding.h"
#include <iostream>

MathsBuilding::MathsBuilding()
    : AcademicBuilding("Maths Building") {}

void MathsBuilding::enter_building(Student& student) {
    reduce_social_battery(student);

    // Get the questions for this building
    ask_maths_question(student);
}

void MathsBuilding::ask_maths_question(Student& student) {
    int level = student.get_level();
    std::vector<Question> math_questions = create_math_questions();

    if (level > 0 && level <= math_questions.size()) {
        Question& question = math_questions[level - 1];  // Get question based on the level
        student.answer_question(question);
    } else {
        std::cout << "No more questions for this level.\n";
    }
}

void MathsBuilding::reduce_social_battery(Student& student) {
    student.add_to_history("Visited Maths Building, social battery decreased.");
    student.get_social_battery().reduce_battery(10);  // Updated to use the getter
}

void MathsBuilding::increase_difficulty(Question& question, int level) {
    // Adjust the difficulty of the question (modify this method if you add difficulty to Question)
    std::cout << "Difficulty increased to level: " << level << "\n";
    // Currently, no difficulty adjustment method exists in Question
}
