//
// Created by Jobin Johnson on 09/03/20.
//

#ifndef RED_CHANNEL_EXTRACT_MENU_HPP
#define RED_CHANNEL_EXTRACT_MENU_HPP

#define NO_MENU_ITEMS 3

#include <string>

class Menu {

private:
    std::string menuItems[NO_MENU_ITEMS] = {
            "Create new Video",
            "All Videos",
            "Log Out"
    };

public:
    void printMenu();
    int choose();

    int displayAndSelect();


};


#endif //RED_CHANNEL_EXTRACT_MENU_HPP
