#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

using namespace std;

class Question {
private:
    string questionText;
    vector<string> choices;
    char correctAnswer;

public:
    Question(string text, vector<string> options, char answer);

    void displayQuestion() const;
    bool checkAnswer(char answer) const;
};

#endif