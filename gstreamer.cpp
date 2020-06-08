#include "GStreamerConfig.h"
#include <iostream>
#include <cstdio>
#include <gst/gst.h>

void log(const std::string &msg)
{
    std::cout << msg << std::endl;
}

int main(int argc, char** argv)
{
    GstElement *pipeline = nullptr;
    GstBus *bus = nullptr;
    GstMessage *msg = nullptr;

    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << GStreamer_VERSION_MAJOR << "." << GStreamer_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    gst_init (&argc, &argv);

    GError* err;
    pipeline = gst_parse_launch(
        "playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
        &err);

    if( err != NULL )
    {
        std::printf("gstreamer decoder failed to create pipeline\n");
        std::printf("  (%s)\n", err->message);
        g_error_free(err);
    }
    
    if (pipeline == nullptr)
    {
        log("Pipeline was nullptr");
        return 1;
    }

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline);
    int args = GST_MESSAGE_ERROR | GST_MESSAGE_EOS;
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GstMessageType(args));

    // clean up
    if (msg != nullptr)
    {
        gst_message_unref (msg);
    }

    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
}