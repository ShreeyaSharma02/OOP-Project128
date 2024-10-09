#ifndef UNIBAR_H
#define UNIBAR_H

#include "Building.h"

class UniBar : public Building {
public:
    UniBar();
    void enter_building(Student& student) override;
    void recharge(Student& student);
};

#endif // UNIBAR_H
