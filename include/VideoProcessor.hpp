//
// Created by Jobin Johnson on 09/03/20.
//

#ifndef RED_CHANNEL_EXTRACT_VIDEOPROCESSOR_HPP
#define RED_CHANNEL_EXTRACT_VIDEOPROCESSOR_HPP

#define VIDEO_SOURCE_DEFAULT 0

#include <opencv2/opencv.hpp>
#include <opencv2/videoio/legacy/constants_c.h>

class VideoProcessor {

protected:
    int videoInputDeviceID;
    int duration = 10;

public:
    void capture();

    void setCaptureDevice(int device);

    std::string getFileName();

    void setDuration(int duration) {
        this->duration = duration;
    }

    int getDuraion() {
        return this->duration;
    }

};


#endif //RED_CHANNEL_EXTRACT_VIDEOPROCESSOR_HPP
