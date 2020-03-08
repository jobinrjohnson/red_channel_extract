//
// Created by Jobin Johnson on 08/03/20.
//

#ifndef RED_CHANNEL_EXTRACT_AUTH_HPP
#define RED_CHANNEL_EXTRACT_AUTH_HPP

#define AUTH_PROVIDER_SIMPLE 1


class Auth {

private:
    int numberOfAttempts = 3;
    int authProvider = AUTH_PROVIDER_SIMPLE;


public:

    int setAuthProvider(int authProvider);

    void setNumberOfAttempts(int number);

    bool auth();

};


#endif //RED_CHANNEL_EXTRACT_AUTH_HPP
