#ifndef INTERACTION_H
#define INTERACTION_H

#include "Student.h"
#include "Building.h"
#include <vector>

class Interaction {
private:
    bool game_state;
    Student* student;
    std::vector<Building*> buildings;

public:
    Interaction();
    ~Interaction();
    void start_game();
    void manage_interaction();
    void end_game();
};

#endif // INTERACTION_H
