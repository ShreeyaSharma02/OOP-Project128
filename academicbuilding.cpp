#include "AcademicBuilding.h"
//parent class for building named cs and math
AcademicBuilding::AcademicBuilding(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color)
    : Building(name, size, position, color) {}