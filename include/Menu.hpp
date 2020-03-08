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

    void performAction(int actionId);

    void chooseInfinitely();

protected:
    void Action_Logout();

    void Action_FileList();

    void Action_CreateVideo();


};


#endif //RED_CHANNEL_EXTRACT_MENU_HPP
