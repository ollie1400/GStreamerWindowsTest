cmake_minimum_required(VERSION 3.10)

# gstreamer library
set(GSTREAMER_LIB_DIR "D:/gstreamer/1.0/x86_64/lib/gstreamer-1.0/")

# set the project name
project(GStreamer VERSION 1.0)

configure_file(GStreamerConfig.h.in GStreamerConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_compile_options($<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/DEBUG>)

# add the executable
add_executable(GStreamer gstreamer.cpp)

target_include_directories(GStreamer PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "D:/gstreamer/1.0/x86_64/include/gstreamer-1.0/"
                           "D:/gstreamer/1.0/x86_64/include/glib-2.0/"
                           "D:/gstreamer/1.0/x86_64/lib/glib-2.0/include/"
                           )

target_link_directories(GStreamer PUBLIC
                            "D:/gstreamer/1.0/x86_64/lib/"
                            "D:/gstreamer/1.0/x86_64/lib/gstreamer-1.0/"
                            )

target_link_libraries(GStreamer PUBLIC
                            "gstreamer-1.0.lib"
                            )