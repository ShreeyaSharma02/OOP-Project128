#ifndef INTERACTION_H
#define INTERACTION_H

class Interaction {
public:
    void manage_interaction(Student& student, Building& building) {
        building.enter_building(student);
    }
    void start_game() {
        // Initialize game state
    }
    void end_game() {
        // Final stats logic
    }
};

#endif // INTERACTION_H
