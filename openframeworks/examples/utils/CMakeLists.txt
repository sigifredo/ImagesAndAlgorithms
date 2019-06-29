include_directories(include)

set (HDRS
include/BaseApplication.hpp
)

set (SRCS
src/BaseApplication.cpp
)

add_library(utils ${SRCS})
add_executable(prueba src/prueba.cpp)

target_link_libraries(utils ${OF_LIBS})
target_link_libraries(prueba utils)
