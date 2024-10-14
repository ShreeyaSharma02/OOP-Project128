/* Testing level system by verifying that the students level increases when grades exceed threshold

Expected Output: 
Initial level: 1
Initial grades: 0
You've reached level 2!
Grades after 10 points: 10
Current level: 2
You've reached level 3! You've won the game!
Grades after 20 more points: 30
Current level: 3

*/

#include "Student.h"
#include <iostream>

void test_level_system() {
    Student student("Mateo");

    // Initial state
    std::cout << "Initial level: " << student.get_level() << std::endl;
    std::cout << "Initial grades: " << student.get_grades() << std::endl;

    // Increase grades and check for level up
    student.increase_grades(10.0);
    std::cout << "Grades after 10 points: " << student.get_grades() << std::endl;
    std::cout << "Current level: " << student.get_level() << std::endl;

    student.increase_grades(20.0);  // This should cause level up to 3
    std::cout << "Grades after 20 more points: " << student.get_grades() << std::endl;
    std::cout << "Current level: " << student.get_level() << std::endl;
}

int main() {
    test_level_system();
    return 0;
}
