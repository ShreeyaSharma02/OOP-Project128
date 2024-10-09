#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "SocialBattery.h"
#include "Questions.h"
#include <vector>
#include <iostream>

class Student {
private:
    std::string name;
    int level;
    double grades;
    SocialBattery social_battery;  // Keep this private
    std::vector<std::string> history;  // For storing question history

public:
    // Constructor for initializing student with a name
    Student(const std::string& name);

    // Method for answering a question
    void answer_question(Question& question);

    // Method to visit a building
    void visit_building(class Building* building);

    // Getters
    int get_social_battery_level() const; // Change this to get battery level
    void reduce_social_battery(int amount);
    void recharge_social_battery();
    void level_up();
    int get_level() const;
    double get_grades() const;
    void add_to_history(const std::string& record);
    void view_history() const;

    // Getter for social_battery
    SocialBattery& get_social_battery(); // Keep the reference for internal use

    // Overloaded stream insertion operator for output
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif // STUDENT_H
