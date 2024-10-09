#include "ComputerScienceBuilding.h"
#include <iostream>

ComputerScienceBuilding::ComputerScienceBuilding()
    : AcademicBuilding("Computer Science Building") {}

void ComputerScienceBuilding::enter_building(Student& student) {
    reduce_social_battery(student);
    ask_cs_question(student);
}

void ComputerScienceBuilding::ask_cs_question(Student& student) {
    int level = student.get_level();
    std::vector<Question> cs_questions = create_cs_questions();

    if (level > 0 && level <= cs_questions.size()) {
        Question& question = cs_questions[level - 1];  // Get question based on the level
        student.answer_question(question);
    } else {
        std::cout << "No more questions for this level.\n";
    }
}

void ComputerScienceBuilding::reduce_social_battery(Student& student) {
    student.add_to_history("Visited Computer Science Building, social battery decreased.");
    student.get_social_battery().reduce_battery(10);  // Updated to use the getter
}

void ComputerScienceBuilding::increase_difficulty(Question& question, int level) {
    std::cout << "Difficulty increased to level: " << level << "\n";
    // Adjust the difficulty of the question (modify this method if you add difficulty to Question)
}
