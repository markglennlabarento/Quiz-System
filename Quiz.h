#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include "Question.h"
#include "Student.h"

using namespace std;

class Quiz {
private:
    vector<Question> questions;
    Student student;

public:
    Quiz();
    void loadQuestions();
    void startQuiz();
    void calculateScore(int correctAnswers);
    void displayResult() const;
};

#endif