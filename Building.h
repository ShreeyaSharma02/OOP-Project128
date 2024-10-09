#ifndef BUILDING_H
#define BUILDING_H

#include "Student.h"

class Building {
protected:
    std::string building_name;

public:
    Building(const std::string& name);
    virtual void enter_building(Student& student) = 0; // Pure virtual function
    std::string get_building_name() const;
    virtual ~Building() = default;
};

#endif // BUILDING_H
