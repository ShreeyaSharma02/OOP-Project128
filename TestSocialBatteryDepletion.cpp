/* Testing for social battery depletion where the student's social battery is completely delpeted and very how the game handles this.

Expected Output:
Reducing social battery...
Social battery level after depletion: 0
Warning: Social battery fully depleted. Student may be restricted from further actions.

*/

#include "Student.h"
#include <iostream>

void test_social_battery_depletion() {
    Student student("Mateo");

    // Reduce social battery to 0
    std::cout << "Reducing social battery...\n";
    student.get_social_battery().reduce_battery(100);  // Deplete the battery completely

    // Check the current battery level
    std::cout << "Social battery level after depletion: " << student.get_social_battery().get_current_battery() << "\n";

    // Verify if there are any consequences in the game (like restricting actions)
    if (student.get_social_battery().get_current_battery() == 0) {
        std::cout << "Warning: Social battery fully depleted. Student may be restricted from further actions.\n";
    }
}

int main() {
    test_social_battery_depletion();
    return 0;
}
