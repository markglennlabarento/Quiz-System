#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student();

    void setName(const string& studentName);
    string getName() const;

    void setScore(int studentScore);
    int getScore() const;
};

#endif