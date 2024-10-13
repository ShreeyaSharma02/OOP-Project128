#ifndef INTERACTION_H
#define INTERACTION_H

#include "Student.h"
#include "Building.h"
#include "HUD.h"  // Include the HUD header
#include <vector>
#include <SFML/Graphics.hpp>

class Interaction {
private:
    bool game_state;
    Student* student;
    std::vector<Building*> buildings;

    // Add a texture and sprite for the background (map)
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Declare the HUD instance
    HUD hud;

public:
    Interaction();
    ~Interaction();
    void start_game();
    void manage_interaction(sf::RenderWindow& window);  // Pass window for rendering
    void end_game();

    // Add a method to show the game-winning menu
    void show_win_menu(sf::RenderWindow& window);
};

#endif // INTERACTION_H