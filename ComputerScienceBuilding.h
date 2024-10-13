#ifndef COMPUTERSCIENCEBUILDING_H
#define COMPUTERSCIENCEBUILDING_H

#include "AcademicBuilding.h"
#include "Questions.h"
#include <vector>

class ComputerScienceBuilding : public AcademicBuilding {
private:
    std::vector<Question> create_cs_questions();
    sf::Texture texture; // Add this to manage the specific texture

public:
    ComputerScienceBuilding(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);
    void enter_building(Student& student) override;
    void ask_cs_question(Student& student);
    void reduce_social_battery(Student& student) override;
    void increase_difficulty(Question& question, int level);
};

#endif // COMPUTERSCIENCEBUILDING_H
