#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

class Question {
private:
    std::string question_text;
    std::vector<std::string> options; // Options for the multiple-choice question
    int correct_option_index;         // Index of the correct option
    double difficulty;                // Difficulty level of the question

public:
    // Constructor for a multiple-choice question
    Question(const std::string& text, const std::vector<std::string>& opts, int correct_index, double diff)
        : question_text(text), options(opts), correct_option_index(correct_index), difficulty(diff) {}

    // Getters
    std::string get_question() const { return question_text; }
    std::vector<std::string> get_options() const { return options; }
    double get_difficulty() const { return difficulty; }

    // Check if the answer is correct
    bool check_answer(int answer_index) const {
        return answer_index == correct_option_index;
    }

    // Get the correct answer text
    std::string get_correct_answer() const {
        return options[correct_option_index];
    }

    // Adjust the difficulty of the question
    void adjust_difficulty(double new_difficulty) {
        difficulty = new_difficulty;
    }
};

#endif // QUESTIONS_H
