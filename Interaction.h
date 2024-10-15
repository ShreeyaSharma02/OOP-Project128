#ifndef INTERACTION_H
#define INTERACTION_H

#include "Student.h"
#include "Building.h"
#include "HUD.h"  
#include <vector>
#include <SFML/Graphics.hpp>

class Interaction {
private:
    bool game_state;
    Student* student;
    std::vector<Building*> buildings;

    // Add a texture and sprite for the background 
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // HUD instance
    HUD hud;

public:
    Interaction();
    ~Interaction();
    void start_game();
    void manage_interaction(sf::RenderWindow& window);  // Pass window for rendering
    void end_game();

    // showing the game-winning menu
    void show_win_menu(sf::RenderWindow& window);
};

#endif 