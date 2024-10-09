#include <iostream>
#include "Student.h"
#include "MathsBuilding.h"
#include "ComputerScienceBuilding.h"
#include "UniBar.h"
#include "MainHub.h"

int main() {
    Student student("Alice");
    MathsBuilding mathsBuilding;
    ComputerScienceBuilding csBuilding;
    UniBar uniBar;
    MainHub mainHub;

    // Simulation of visiting buildings
    student.visit_building(&mathsBuilding);
    student.visit_building(&csBuilding);
    student.visit_building(&uniBar);
    student.visit_building(&mainHub);

    // Final stats and history
    std::cout << student;

    return 0;
}
