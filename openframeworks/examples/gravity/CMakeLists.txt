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

add_executable(gravity.base src/base.cpp ${SRCS})
add_executable(gravity.of src/main.cpp ${SRCS})

target_link_libraries(gravity.base ${OF_LIBS} glut)
target_link_libraries(gravity.of ${OF_LIBS} utils)
