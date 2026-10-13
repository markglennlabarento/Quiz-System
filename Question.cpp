#include "Question.h"
#include <iostream>
#include <cctype>

using namespace std;

Question::Question(string text,
                   vector<string> options,
                   char answer)
    : questionText(text),
      choices(options),
      correctAnswer(
          static_cast<char>(
              toupper(static_cast<unsigned char>(answer))
          )
      ) {
}

void Question::displayQuestion() const {
    cout << "\n" << questionText << "\n";

    char option = 'A';

    for (const string& choice : choices) {
        cout << option++ << ". "
             << choice << "\n";
    }
}

bool Question::checkAnswer(char answer) const {
    answer = static_cast<char>(
        toupper(static_cast<unsigned char>(answer))
    );

    return answer == correctAnswer;
}