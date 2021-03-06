//
// Created by Jobin Johnson on 09/03/20.
//

#include <sys/time.h>
#include "../include/VideoProcessor.hpp"

using namespace cv;

void VideoProcessor::setCaptureDevice(int device) {
    this->videoInputDeviceID = device;
}

std::string VideoProcessor::getFileName() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    char fileName[60];
    sprintf(fileName, "recorded/video_%ld.mp4", ms);\
    return fileName;
}

void VideoProcessor::capture() {

    cv::VideoCapture input(this->videoInputDeviceID);
    if (!input.isOpened()) {
        std::cout << "Error while opening video stream";
        return;
    }

    int extension = static_cast<int>(input.get(CV_CAP_PROP_FOURCC));
    Size size = Size((int) input.get(CV_CAP_PROP_FRAME_WIDTH),
                     (int) input.get(CV_CAP_PROP_FRAME_HEIGHT));

    std::string fileName = this->getFileName();

    std::cout << std::endl << "Saving file to " << fileName << std::endl;

    cv::VideoWriter videoOutput(
            fileName,
            VideoWriter::fourcc('m', 'p', '4', 'v'),
            input.get(CV_CAP_PROP_FPS),
            size,
            false
    );

    long int i = 0;
    while (i++ < input.get(CV_CAP_PROP_FPS) * this->getDuraion()) {

        cv::Mat frame;
        input >> frame;

        if (frame.empty()) {
            std::cout << "Unable to read frame";
            break;
        }

        // Extract red
        cv::Mat redFrame;
        extractChannel(frame, redFrame, 2);

        // Gaussian Blur
        Mat blurred;
        GaussianBlur(redFrame, blurred, Size(5, 5), 0, 0);

        videoOutput.write(blurred);
    }

    videoOutput.release();
    input.release();

}