#include "Building.h"

Building::Building(const std::string& name)
    : building_name(name) {}

std::string Building::get_building_name() const {
    return building_name;
}
