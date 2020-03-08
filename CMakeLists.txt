cmake_minimum_required(VERSION 3.16)
project(red_channel_extract)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(red_channel_extract main.cpp Auth.cpp include/Auth.hpp Menu.cpp include/Menu.hpp VideoProcessor.cpp include/VideoProcessor.hpp)
target_link_libraries(red_channel_extract ${OpenCV_LIBS})
