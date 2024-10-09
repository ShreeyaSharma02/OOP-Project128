#ifndef COMPUTERSCIENCEBUILDING_H
#define COMPUTERSCIENCEBUILDING_H

#include "Building.h"

class ComputerScienceBuilding : public Building {
public:
    ComputerScienceBuilding() : Building("Computer Science Building") {}

    void enter_building(Student& student) override {
        // Ask CS question logic
        // student.question_answer(...)
        // student.socialBattery.reduce_battery();
    }
};

#endif // COMPUTERSCIENCEBUILDING_H
