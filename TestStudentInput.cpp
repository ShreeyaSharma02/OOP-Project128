/* Testing student input when when student answers a question correctly or incorrectly, and the program updates the student's grades and answer stats

Expected Output:
*Answering question correctly*
Correct answers: 1
Grades: 5
*Answering question incorrectly*
Incorrect answers: 1

*/

#include <iostream>
#include "Student.h"
#include "Questions.h"

void test_student_answers() {
    Student student("Test Student");
    Question question("What is 2 + 2?", {"3", "4", "5"}, 1, 1.0);

    // Simulate player answering correctly
    std::cout << "*Answering question correctly*" << std::endl;
    student.answer_question(question, 1);
    std::cout << "Correct answers: " << student.get_correct_answers() << std::endl;
    std::cout << "Grades: " << student.get_grades() << "\n";

    // Simulate player answering incorrectly
    std::cout << "*Answering question incorrectly*" << std::endl;
    student.answer_question(question, 0);
    std::cout << "Incorrect answers: " << student.get_incorrect_answers() << std::endl;
}

int main() {
    test_student_answers();
    return 0;
}
