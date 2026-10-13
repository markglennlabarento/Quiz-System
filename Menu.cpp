#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

void Menu::displayMenu() const {
    cout << "\n========== QUIZ SYSTEM ==========\n";
    cout << "1. Start Quiz\n";
    cout << "2. Exit\n";
    cout << "=================================\n";
}

int Menu::getChoice() const {
    int choice;

    while (true) {
        cout << "Enter choice: ";

        if (cin >> choice) {
            if (choice == 1 || choice == 2) {
                return choice;
            }

            cout << "Choose 1 or 2.\n";
        } else {
            if (cin.eof()) {
                return 2;
            }

            cout << "Invalid input. Enter a number.\n";
            cin.clear();
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}