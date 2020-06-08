To build:

Install `gstreamer-1.0-msvc-x86_64-1.16.2.msi` and `gstreamer-1.0-devel-msvc-x86_64-1.16.2.msi` from `https://gstreamer.freedesktop.org/data/pkg/windows/1.16.2/`

Project is configured to look for headers in:
```
"D:/gstreamer/1.0/x86_64/include/gstreamer-1.0/"
"D:/gstreamer/1.0/x86_64/include/glib-2.0/"
"D:/gstreamer/1.0/x86_64/lib/glib-2.0/include/"
```

then run
```
cmake CmakeLists.txt
cmake --build .
```

To run:
`Debug\GStreamer.exe`