#include "Questions.h"
#include <vector>

std::vector<Question> create_math_questions() {
    return {
        Question("What is 1 + 1?", {"1", "2", "3", "5"}, 1, 1), // Level 1
        Question("What is 1000 * 34 + 50?", {"34050", "3400", "30", "45"}, 0, 2), // Level 2
        Question("What is the value of sin 90?", {"1", "0", "2", "1.5"}, 0, 3) // Level 3
    };
}

std::vector<Question> create_cs_questions() {
    return {
        Question("Who invented C++?", {"Dennis Ritchie", "Ken Thompson", "Brian Kernighan", "Bjarne Stroustrup"}, 3, 1), // Level 1
        Question("Which of the following is used for comments in C++?", {"/* comment */", "// comment */", "// comment", "both // comment or /* comment */"}, 3, 2), // Level 2
        Question("Which of the following is not a type of Constructor in C++?", {"Default constructor", "Parameterized constructor", "Copy constructor", "Friend constructor"}, 3, 3) // Level 3
    };
}
