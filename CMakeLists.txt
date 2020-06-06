cmake_minimum_required(VERSION 3.10)

# set the project name
project(GStreamer VERSION 1.0)

configure_file(GStreamerConfig.h.in GStreamerConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(GStreamer gstreamer.cpp)

target_include_directories(GStreamer PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )