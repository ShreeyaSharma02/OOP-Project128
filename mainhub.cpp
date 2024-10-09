#include "MainHub.h"
#include <iostream>

MainHub::MainHub()
    : Building("Main Hub") {}

void MainHub::enter_building(Student& student) {
    view_stats(student);
    view_history(student);
}

void MainHub::view_stats(const Student& student) {
    std::cout << student;
}

void MainHub::view_history(const Student& student) {
    student.view_history();
}
