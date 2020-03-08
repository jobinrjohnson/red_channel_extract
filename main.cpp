#include <iostream>
#include <opencv2/opencv.hpp>

#include "include/Auth.hpp"
#include "include/Menu.hpp"

using namespace std;

int main() {

    // Authenticate User
//    Auth auth;
//    auth.setAuthProvider(AUTH_PROVIDER_SIMPLE);
//    if(!auth.auth()){
//        cout<< "Authentication Error" << endl;
//        return  -1;
//    }

    Menu menu;
    menu.chooseInfinitely();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
