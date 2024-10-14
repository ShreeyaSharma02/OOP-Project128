/* Testing what happens when game ends by simulating the student reaching level 3 in grade system (indicator that student has won and verify that game ends) 

Expected Output:
Simulating student progress...
Current grades: 0, Current level: 1
Current grades: 10, Current level: 2
Current grades: 20, Current level: 3
Game ends: Student has won the game!

*/

#include "Student.h"
#include <iostream>

// Test function to verify the game ends when the student wins
void test_game_end_condition() {
    // Create a student object
    Student student("Mateo");

    // Simulate increasing the student's level until they win
    std::cout << "Simulating student progress...\n";

    //Initial stats of student
    std::cout << "Current Grades: " << student.get_grades() << ", Current level: " << student.get_level() << "\n";

    // Simulate multiple level-ups or grade increments
    while (!student.has_won()) {  
        student.increase_grades(10);  // Add grades
        std::cout << "Current grades: " << student.get_grades() << ", Current level: " << student.get_level() << "\n";
    }

    // Check if the game ends by verifying the win condition
    if (student.has_won()) {
        std::cout << "Game ends: Student has won the game!\n";
    } else {
        std::cout << "Game continues: Student has not won yet.\n";
    }
}

int main() {
    test_game_end_condition();
    return 0;
}
