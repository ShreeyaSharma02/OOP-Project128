#include "Interaction.h"
#include "MathsBuilding.h"
#include "ComputerScienceBuilding.h"
#include "UniBar.h"
#include "MainHub.h"
#include <iostream>
#include <limits>

Interaction::Interaction()
    : game_state(false), student(nullptr) {}

Interaction::~Interaction() {
    delete student;
    for (auto building : buildings) {
        delete building;
    }
}

void Interaction::start_game() {
    game_state = true;
    std::string name;
    std::cout << "Enter your student name: ";
    std::getline(std::cin, name);
    student = new Student(name);

    // Initialize buildings
    buildings.push_back(new MathsBuilding());
    buildings.push_back(new ComputerScienceBuilding());
    buildings.push_back(new UniBar());
    buildings.push_back(new MainHub());

    std::cout << "Welcome to the University Simulation Game, " << name << "!\n";
}

void Interaction::manage_interaction() {
    while (game_state) {
        std::cout << "\nSelect a building to visit:\n";
        for (size_t i = 0; i < buildings.size(); ++i) {
            std::cout << i + 1 << ". " << buildings[i]->get_building_name() << "\n";
        }
        std::cout << buildings.size() + 1 << ". Exit Game\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        if (choice > 0 && choice <= buildings.size()) {
            // Check if social battery is low before entering Maths or CS buildings
            if (student->get_social_battery().get_current_battery() <= 0 && 
               (buildings[choice - 1]->get_building_name() == "Maths Building" || 
                buildings[choice - 1]->get_building_name() == "Computer Science Building")) {
                std::cout << "Your social battery is depleted. You need to recharge at the Uni Bar.\n";
                continue; // Skip to the next iteration of the loop
            }
            student->visit_building(buildings[choice - 1]);
        } else if (choice == buildings.size() + 1) {
            end_game();
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }

        if (student->get_level() >= 5) {
            std::cout << "Congratulations! You've reached the maximum level!\n";
            end_game();
        }
    }
}

void Interaction::end_game() {
    game_state = false;
    std::cout << "Thank you for playing the University Simulation Game!\n";
}
