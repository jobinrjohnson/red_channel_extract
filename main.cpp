#include <iostream>
#include <opencv2/opencv.hpp>
#include <dirent.h>

#include "include/Auth.hpp"
#include "include/Menu.hpp"
#include "include/VideoProcessor.hpp"

using namespace std;

void listDir() {
    DIR *dirp;
    struct dirent *directory;

    dirp = opendir("recorded/");
    if (dirp) {
        cout << "\nAll Videos\n";
        while ((directory = readdir(dirp)) != NULL) {

            std::string dir_name = directory->d_name;

            if (dir_name.compare(".") == 0 || dir_name.compare("..") == 0) {
                continue;
            }

            std::cout << dir_name << endl;
        }

        closedir(dirp);
    }

}

int main() {

    // Authenticate User
    Auth auth;
    auth.setAuthProvider(AUTH_PROVIDER_SIMPLE);
    if (!auth.auth()) {
        cout << "Authentication Error" << endl;
        return -1;
    }

    Menu menu;
    VideoProcessor videoProcessor;
    videoProcessor.setDuration(10);

    while (true) {
        int actionId = menu.displayAndSelect();

        switch (actionId) {
            case 1:
                cout << "\nCapturing Video";
                videoProcessor.setCaptureDevice(VIDEO_SOURCE_DEFAULT);
                videoProcessor.capture();
                cout << "\ncapture complete";
                break;
            case 2:
                listDir();
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
