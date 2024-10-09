#ifndef UNIBAR_H
#define UNIBAR_H

#include "Building.h"

class UniBar : public Building {
public:
    UniBar() : Building("Uni Bar") {}

    void enter_building(Student& student) override {
        // Recharge social battery logic
        // student.socialBattery.recharge_battery();
    }
};

#endif // UNIBAR_H
