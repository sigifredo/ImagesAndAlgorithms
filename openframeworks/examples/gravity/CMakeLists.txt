include_directories(${GLOBAL_INCLUDE_DIR} include)

set (HDRS
include/Color.hpp
include/Particle.hpp
include/Velocity.hpp
)

set (MOC_HDRS
include/GLWidget.hpp
include/MainWindow.hpp
include/PaintGravityHelper.hpp
include/PaintHelperInterface.hpp
include/PaintImageHelper.hpp
)

set (SRCS
src/Color.cpp
src/GLWidget.cpp
src/MainWindow.cpp
src/PaintGravityHelper.cpp
src/PaintImageHelper.cpp
src/Particle.cpp
src/Velocity.cpp
)

qt5_wrap_cpp(MOC_SRCS ${MOC_HDRS})

add_executable(gravity.base src/base.cpp ${SRCS})
add_executable(gravity.qt src/main.cpp ${MOC_SRCS} ${SRCS})

qt5_use_modules(gravity.qt Core Widgets)

target_link_libraries(gravity.base ${OF_LIBS} glut)
target_link_libraries(gravity.qt ${OF_LIBS} utils)
