#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "Building.h"
#include "Student.h"

class AcademicBuilding : public Building {
public:
    AcademicBuilding(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);
    virtual void reduce_social_battery(Student& student) = 0; // Virtual function for academic buildings
};

#endif

