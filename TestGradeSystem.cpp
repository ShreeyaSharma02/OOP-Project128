/* Testing grading system by verifying if grades are correctly incremented when answering questions

Expected Output:
Initial grades: 0
Grades after answering correctly (10 added): 10
Grades after another correct answer (15 added): 25
Grades after adding a large number (999): 1024


*/

#include <iostream>
#include "Student.h"

void test_grading_system() {
    // Create student
    Student student("Mateo");

    // Initial grades
    std::cout << "Initial grades: " << student.get_grades() << std::endl;

    // Increase grades
    student.increase_grades(10);
    std::cout << "Grades after answering correctly (10 added): " << student.get_grades() << std::endl;

    // Increase grades again
    student.increase_grades(15);
    std::cout << "Grades after another correct answer (15 added): " << student.get_grades() << std::endl;

    // Test boundary cases by adding large number
    student.increase_grades(999);
    std::cout << "Grades after adding a large number (999): " << student.get_grades() << std::endl;
}

int main() {
    test_grading_system();
    return 0;
}


