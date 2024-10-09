#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>

class Questions {
private:
    std::string question;
    std::string correct_answer;
    int difficulty;

public:
    Questions(const std::string& q, const std::string& ans, int diff)
        : question(q), correct_answer(ans), difficulty(diff) {}

    bool check_answer(const std::string& answer) {
        return answer == correct_answer;
    }

    void adjust_difficulty(int change) {
        difficulty += change;
    }
};

#endif // QUESTIONS_H
