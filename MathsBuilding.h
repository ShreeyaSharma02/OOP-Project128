#ifndef MATHSBUILDING_H
#define MATHSBUILDING_H

#include "AcademicBuilding.h"
#include "Questions.h"
#include <vector>

class MathsBuilding : public AcademicBuilding {
private:
    std::vector<Question> create_math_questions();
public:
    MathsBuilding();
    void enter_building(Student& student) override;
    void ask_maths_question(Student& student);
    void reduce_social_battery(Student& student) override;
    void increase_difficulty(Question& question, int level);
};

#endif // MATHSBUILDING_H
