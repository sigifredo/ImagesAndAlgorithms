include_directories(${GLOBAL_INCLUDE_DIR} include)

set (HDRS
include/Color.hpp
include/Particle.hpp
include/Velocity.hpp
)

set (SRCS
src/Color.cpp
src/Particle.cpp
src/Velocity.cpp
)

add_executable(gravity src/main.cpp ${SRCS})

target_link_libraries(gravity ${OF_LIBS} glut)
