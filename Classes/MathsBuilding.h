#ifndef MATHSBUILDING_H
#define MATHSBUILDING_H

#include "Building.h"

class MathsBuilding : public Building {
public:
    MathsBuilding() : Building("Maths Building") {}

    void enter_building(Student& student) override {
        // Ask maths question logic
        // student.question_answer(...)
        // student.socialBattery.reduce_battery();
    }
};

#endif // MATHSBUILDING_H
