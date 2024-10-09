#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "Building.h"
#include "Student.h"

class AcademicBuilding : public Building {
public:
    AcademicBuilding(const std::string& name);
    virtual void reduce_social_battery(Student& student) = 0; // Abstract functionality for academic buildings
};

#endif // ACADEMICBUILDING_H
