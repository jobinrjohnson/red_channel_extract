//
// Created by Jobin Johnson on 09/03/20.
//

#include <iostream>
#include "../include/Menu.hpp"

void Menu::printMenu() {

    int i, selection;

    std::cout << std::endl << std::endl;
    for (i = 0; i < NO_MENU_ITEMS; i++) {
        std::cout << i + 1 << " " << this->menuItems[i] << std::endl;
    }

}

int Menu::choose() {

    std::cout << "Select Action : ";

    int selection;
    std::cin >> selection;
    return selection;

}


int Menu::displayAndSelect() {
    this->printMenu();
    int choice = this->choose();
    return choice;

}


