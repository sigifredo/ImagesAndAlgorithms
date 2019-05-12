
set(OF_LIB_PATH "/opt/raziel/openFrameworks/libs/")

set(OF_LIBS_INCLUDE_DIRS
${OF_LIB_PATH}/glm/include/
${OF_LIB_PATH}/json/include/
${OF_LIB_PATH}/kiss/include/
${OF_LIB_PATH}/openFrameworks
${OF_LIB_PATH}/openFrameworks/3d/
${OF_LIB_PATH}/openFrameworks/app/
${OF_LIB_PATH}/openFrameworks/communication/
${OF_LIB_PATH}/openFrameworks/events/
${OF_LIB_PATH}/openFrameworks/gl/
${OF_LIB_PATH}/openFrameworks/graphics/
${OF_LIB_PATH}/openFrameworks/math/
${OF_LIB_PATH}/openFrameworks/sound/
${OF_LIB_PATH}/openFrameworks/types/
${OF_LIB_PATH}/openFrameworks/utils/
${OF_LIB_PATH}/openFrameworks/video/
${OF_LIB_PATH}/tess2/include/
${OF_LIB_PATH}/utf8/include/
/usr/include/cairo/
/usr/include/glib-2.0/
/usr/include/gstreamer-1.0/
/usr/lib/x86_64-linux-gnu/glib-2.0/include/
)

set(OF_LIBS
${OF_LIB_PATH}/openFrameworksCompiled/lib/linux64/libopenFrameworks.a
/lib/x86_64-linux-gnu/libpthread.so.0
/lib/x86_64-linux-gnu/libudev.so.1
/lib/x86_64-linux-gnu/libz.so.1
/opt/raziel/openFrameworks/libs/kiss/lib/linux64/libkiss.a
/opt/raziel/openFrameworks/libs/tess2/lib/linux64/libtess2.a
/usr/lib/x86_64-linux-gnu/gstreamer-1.0/libgstapp.so
/usr/lib/x86_64-linux-gnu/gstreamer-1.0/libgstopengl.so
/usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/usr/lib/x86_64-linux-gnu/libboost_system.so.1.67.0
/usr/lib/x86_64-linux-gnu/libcairo.a
/usr/lib/x86_64-linux-gnu/libcurl.a
/usr/lib/x86_64-linux-gnu/libfontconfig.so
/usr/lib/x86_64-linux-gnu/libfreeimage.so
/usr/lib/x86_64-linux-gnu/libfreetype.so.6
/usr/lib/x86_64-linux-gnu/libGLEW.so
/usr/lib/x86_64-linux-gnu/libglfw.so
/usr/lib/x86_64-linux-gnu/libglib-2.0.so.0
/usr/lib/x86_64-linux-gnu/libGL.so
/usr/lib/x86_64-linux-gnu/libgnutls.so
/usr/lib/x86_64-linux-gnu/libgobject-2.0.so.0
/usr/lib/x86_64-linux-gnu/libgssapi_krb5.so.2
/usr/lib/x86_64-linux-gnu/libgstapp-1.0.so.0
/usr/lib/x86_64-linux-gnu/libgstbase-1.0.so
/usr/lib/x86_64-linux-gnu/libgstbase-1.0.so
/usr/lib/x86_64-linux-gnu/libgstcheck-1.0.so
/usr/lib/x86_64-linux-gnu/libgstcontroller-1.0.so
/usr/lib/x86_64-linux-gnu/libgstnet-1.0.so
/usr/lib/x86_64-linux-gnu/libgstreamer-1.0.so
/usr/lib/x86_64-linux-gnu/libgstreamer-1.0.so
/usr/lib/x86_64-linux-gnu/libgstvideo-1.0.so.0
/usr/lib/x86_64-linux-gnu/libidn2.so.0
/usr/lib/x86_64-linux-gnu/liblber-2.4.so.2
/usr/lib/x86_64-linux-gnu/libldap.so
/usr/lib/x86_64-linux-gnu/libmpg123.so
/usr/lib/x86_64-linux-gnu/libnettle.so.6
/usr/lib/x86_64-linux-gnu/libnghttp2.so.14
/usr/lib/x86_64-linux-gnu/libopenal.so
/usr/lib/x86_64-linux-gnu/libpixman-1.so
/usr/lib/x86_64-linux-gnu/libpng16.so.16
/usr/lib/x86_64-linux-gnu/libpsl.so.5
/usr/lib/x86_64-linux-gnu/librtmp.so.1
/usr/lib/x86_64-linux-gnu/libsndfile.so
/usr/lib/x86_64-linux-gnu/libssh2.so.1
/usr/lib/x86_64-linux-gnu/liburiparser.so
/usr/lib/x86_64-linux-gnu/libX11.so)

include_directories(${OF_LIBS_INCLUDE_DIRS})