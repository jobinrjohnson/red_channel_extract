//
// Created by Jobin Johnson on 09/03/20.
//

#include <iostream>
#include "include/Menu.hpp"

void Menu::printMenu() {

    int i, selection;

    std::cout << std::endl;
    for (i = 0; i < NO_MENU_ITEMS; i++) {
        std::cout << this->menuItems[i] << std::endl;
    }

}

int Menu::choose() {

    std::cout << "Select Action : ";

    int selection;
    std::cin >> selection;
    return selection;

}

void Menu::performAction(int actionId) {


    switch (actionId) {
        case 3:
            this->Action_Logout();
            break;
    }

}

void Menu::chooseInfinitely() {

    while (true) {
        this->printMenu();
        int choice = this->choose();
        this->performAction(choice);
    }

}

void Menu::Action_Logout() {
    std::cout << std::endl << "Logged out." << std::endl;
    exit(0);
}

void Menu::Action_CreateVideo() {

}

void Menu::Action_FileList() {

}

