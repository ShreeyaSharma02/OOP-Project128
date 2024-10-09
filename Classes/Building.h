#ifndef BUILDING_H
#define BUILDING_H

#include <string>

class Building {
protected:
    std::string building_name;

public:
    Building(const std::string& name) : building_name(name) {}
    virtual void enter_building(class Student& student) = 0; // Pure virtual function
};

#endif // BUILDING_H
