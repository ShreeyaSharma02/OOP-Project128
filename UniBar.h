#ifndef UNIBAR_H
#define UNIBAR_H

#include "Building.h"

class UniBar : public Building {
private:
    sf::Texture texture; // Add this to manage the specific texture

public:
    UniBar(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);
    void enter_building(Student& student) override;
    void recharge(Student& student);
};

#endif
