#ifndef MAINHUB_H
#define MAINHUB_H

#include "Building.h"
#include "Student.h"

class MainHub : public Building {
public:
    MainHub(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);  // Constructor with SFML parameters
    void enter_building(Student& student) override;  // Override the pure virtual function
    void view_stats(const Student& student);         // Display student stats
    void view_history(const Student& student);       // Display student history
    void upgrade_stats(Student& student);            // Upgrade student stats (optional functionality)
};

#endif // MAINHUB_H