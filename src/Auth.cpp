//
// Created by Jobin Johnson on 08/03/20.
//

#include <string>
#include <iostream>
#include "../include/Auth.hpp"

bool Auth::auth() {
    std::string userName;
    std::string password;

    int i = 0;

    while (i++ < this->numberOfAttempts) {

        std::cout << "Enter Your Username : ";
        std::cin >> userName;

        std::cout << "Enter Your Password : ";
        std::cin >> password;

        if (userName.compare("user") == 0 && password.compare("password") == 0) {
            return true;
        }

        std::cout << "Username or password incorrect." << std::endl;

    }

    std::cout << "Authentication failure." << std::endl;

    return false;
}

void Auth::setNumberOfAttempts(int number){
    this->numberOfAttempts = number;
}

int Auth::setAuthProvider(int authProvider) {

    switch (authProvider) {
        case AUTH_PROVIDER_SIMPLE:
            break;
        default:
            throw std::invalid_argument("Invalid auth provider");
    }

    this->authProvider = authProvider;

    return authProvider;
}
