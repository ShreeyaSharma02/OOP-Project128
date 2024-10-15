#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

class Question {
private:
    std::string question_text;
    std::vector<std::string> options;
    int correct_option;
    double difficulty;

public:
    // Handling multiple-choice questions
    Question(const std::string& text, const std::vector<std::string>& opts, int correct_index, double diff)
        : question_text(text), options(opts), correct_option(correct_index), difficulty(diff) {}

    const std::string& get_text() const {
        return question_text;
    }

    const std::vector<std::string>& get_options() const {
        return options;
    }

    int get_correct_option() const {
        return correct_option;
    }

    double get_difficulty() const {
        return difficulty;
    }
};

#endif 
