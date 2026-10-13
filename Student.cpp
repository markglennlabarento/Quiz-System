#include "Student.h"

using namespace std;

Student::Student() {
    name = "";
    score = 0;
}

void Student::setName(const string& studentName) {
    name = studentName;
}

string Student::getName() const {
    return name;
}

void Student::setScore(int studentScore) {
    score = studentScore;
}

int Student::getScore() const {
    return score;
}