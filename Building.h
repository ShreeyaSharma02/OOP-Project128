#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>
#include "Student.h"

class Building {
protected:
    sf::RectangleShape shape;
    sf::Texture texture;  
    std::string building_name;

public:
    Building(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);
    virtual void enter_building(Student& student) = 0; // Pure virtual function
    std::string get_building_name() const;
    void draw(sf::RenderWindow& window); // Draw the building 
    bool checkCollision(const Student& student); // Check for collision with the player
    virtual ~Building() = default;
};

#endif
