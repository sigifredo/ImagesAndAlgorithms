project(ofia)
cmake_minimum_required(VERSION 3.1.0)

include("config/deps.cmake")
include("config/ofia.cmake")

set (HDRS
)

set (SRCS
src/OFApp.cpp
)

add_executable(example1 ${SRCS} src/main.cpp)
target_link_libraries(example1 ${OF_LIBS})
