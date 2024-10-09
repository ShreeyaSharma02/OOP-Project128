#ifndef MAINHUB_H
#define MAINHUB_H

#include "Building.h"

class MainHub : public Building {
public:
    MainHub() : Building("Main Hub") {}

    void enter_building(Student& student) override {
        // Display stats logic
    }
};

#endif // MAINHUB_H
