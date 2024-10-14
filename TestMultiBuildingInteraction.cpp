/* Testing mutiple building interaction by interacting with multiple buildings and if output is as expected

Expected Output:
Student interacted with MathsBuilding.
*get's asked maths related question*
Student's social battery: 90
Student interacted with UniBar.
Student's social battery after recharge: 100

*/

#include "Student.h"
#include "MathsBuilding.h"
#include "UniBar.h"
#include <iostream>

void test_multiple_building_interaction() {
    Student student("Mateo");

    // Create different buildings
    MathsBuilding mathsBuilding({100, 100}, {50, 50}, sf::Color::Red);
    UniBar uniBar({200, 200}, {50, 50}, sf::Color::Green);

    // Simulate entering MathsBuilding
    mathsBuilding.enter_building(student);
    std::cout << "Student interacted with MathsBuilding." << std::endl;

    // Checking student's social battery has lowered
    std::cout << "Student's social battery: " << student.get_social_battery().get_current_battery() << std::endl;

    // Simulate entering UniBar
    uniBar.enter_building(student);
    std::cout << "Student interacted with UniBar." << std::endl;

    // Testing if social battery has recharged after entering unibar
     std::cout << "Student's social battery after recharge: " << student.get_social_battery().get_current_battery() << std::endl;
}

int main() {
    test_multiple_building_interaction();
    return 0;
}
