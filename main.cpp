#include <iostream>
#include <opencv2/opencv.hpp>

#include "include/Auth.hpp"
#include "include/Menu.hpp"
#include "include/VideoProcessor.hpp"

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
    VideoProcessor videoProcessor;
    videoProcessor.setDuration(10);

    while (true) {
        int actionId = menu.displayAndSelect();

        switch (actionId) {
            case 1:
                videoProcessor.setCaptureDevice(VIDEO_SOURCE_DEFAULT);
                videoProcessor.capture();
                break;
            case 2:
                break;
            case 3:
                std::cout << std::endl << "Logged out." << std::endl;
                exit(0);
            default:
                std::cout << std::endl << "Select an option." << std::endl;
                break;
        }
    }
    return 0;
}
