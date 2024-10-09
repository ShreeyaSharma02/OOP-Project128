#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "SocialBattery.h"

class Student {
private:
    std::string name;
    int level;
    double grades;
    SocialBattery socialBattery;

public:
    Student(const std::string& name) : name(name), level(1), grades(0.0), socialBattery(100, 0, 0) {}

    void question_answer(double points) {
        grades += points;
       
    }

    void visit_building(class Building& building);

    int get_social_battery() const {
        return socialBattery.get_current_battery();
    }

    int get_level() const {
        return level;
    }

    
};

#endif 
