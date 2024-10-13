#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Student.h"

class HUD {
private:
    sf::Text hudText;
    sf::Font font;

public:
    HUD();
    void update(const Student& student);  // Updates the HUD with student info
    void draw(sf::RenderWindow& window);  // Draw the HUD on the window
};

#endif // HUD_H
