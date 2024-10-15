#ifndef MAINHUB_H
#define MAINHUB_H

#include "Building.h"
#include "Student.h"

class MainHub : public Building {
public:
    MainHub(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);  // Constructor 
    void enter_building(Student& student) override;  // Override the pure virtual function
    void view_stats(const Student& student);         
    void view_history(const Student& student);       
    void upgrade_stats(Student& student);            // Upgrade student stats 
};

#endif