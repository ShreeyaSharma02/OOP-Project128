#include "UniBar.h"
#include <iostream>

UniBar::UniBar()
    : Building("Uni Bar") {}

void UniBar::enter_building(Student& student) {
    recharge(student);
}

void UniBar::recharge(Student& student) {
    student.get_social_battery().recharge_battery(); // Access social_battery via the getter
    std::cout << "Your social battery is fully recharged!\n";
    student.add_to_history("Visited Uni Bar, social battery recharged.");
}