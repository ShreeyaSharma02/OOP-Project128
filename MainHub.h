#ifndef MAINHUB_H
#define MAINHUB_H

#include "Building.h"

class MainHub : public Building {
public:
    MainHub();
    void enter_building(Student& student) override;
    void view_stats(const Student& student);
    void view_history(const Student& student);
};

#endif // MAINHUB_H
