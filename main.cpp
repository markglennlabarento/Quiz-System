#include <iostream>
#include "Menu.h"
#include "Quiz.h"

using namespace std;

int main() {
    Menu menu;
    Quiz quiz;

    int choice;

    do {
        menu.displayMenu();
        choice = menu.getChoice();

        switch (choice) {
            case 1:
                quiz.startQuiz();
                break;

            case 2:
                cout << "\nThank you for using "
                     << "the Quiz System!\n";
                break;
        }

    } while (choice != 2);

    return 0;
}