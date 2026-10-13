#include "Quiz.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

Quiz::Quiz() {
    loadQuestions();
}

void Quiz::loadQuestions() {
    questions.emplace_back(
        "What is the extension of a C++ source file?",
        vector<string>{
            ".html", ".cpp", ".css", ".sql"
        },
        'B'
    );

    questions.emplace_back(
        "Which keyword creates a class in C++?",
        vector<string>{
            "function", "define", "class", "object"
        },
        'C'
    );

    questions.emplace_back(
        "Which access modifier hides class members?",
        vector<string>{
            "public", "private", "static", "return"
        },
        'B'
    );

    questions.emplace_back(
        "Which loop executes while a condition is true?",
        vector<string>{
            "while", "switch", "class", "return"
        },
        'A'
    );

    questions.emplace_back(
        "Which header provides std::vector?",
        vector<string>{
            "<string>", "<iostream>", "<vector>", "<cmath>"
        },
        'C'
    );
}

void Quiz::startQuiz() {
    string name;

    cout << "\nEnter student name: ";
    getline(cin >> ws, name);

    student.setName(name);

    int correctAnswers = 0;

    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "\nQuestion " << i + 1
                  << " of " << questions.size() << "\n";

        questions[i].displayQuestion();

        char answer;

        while (true) {
            cout << "Your answer (A-D): ";

            if (!(cin >> answer)) {
                if (cin.eof()) {
                    return;
                }

                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );
                cout << "Invalid input. Try again.\n";
                continue;
            }

            answer = static_cast<char>(
                toupper(static_cast<unsigned char>(answer))
            );

            if (answer >= 'A' &&
                answer <= 'D') {
                break;
            }

            cout << "Please enter A, B, C, or D.\n";
        }

        if (questions[i].checkAnswer(answer)) {
            cout << "Correct!\n";
            ++correctAnswers;
        } else {
            cout << "Incorrect.\n";
        }
    }

    calculateScore(correctAnswers);
    displayResult();
}

void Quiz::calculateScore(int correctAnswers) {
    student.setScore(correctAnswers);
}

void Quiz::displayResult() const {
    double percentage = 0.0;

    if (!questions.empty()) {
        percentage =
            static_cast<double>(student.getScore())
            / questions.size() * 100.0;
    }

    cout << "\n========== QUIZ RESULT ==========\n";
    cout << "Student: " << student.getName() << "\n";
    cout << "Score: " << student.getScore()
              << " / " << questions.size() << "\n";
    cout << "Percentage: " << percentage << "%\n";

    if (percentage >= 75.0) {
        cout << "Status: Passed\n";
    } else {
        cout << "Status: Failed\n";
    }

    cout << "=================================\n";
}