#ifndef MATHSBUILDING_H
#define MATHSBUILDING_H

#include "AcademicBuilding.h"
#include "Questions.h"
#include <vector>

class MathsBuilding : public AcademicBuilding {
private:
    std::vector<Question> create_math_questions();
    sf::Texture texture; // managing the specific texture

public:
    MathsBuilding(const sf::Vector2f& size, const sf::Vector2f& position, sf::Color color);
    void enter_building(Student& student) override;
    void ask_maths_question(Student& student);
    void reduce_social_battery(Student& student) override;
    void increase_difficulty(Question& question, int level);
};

#endif 


