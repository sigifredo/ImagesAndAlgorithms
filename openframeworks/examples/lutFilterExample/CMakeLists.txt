include_directories(include)

set (HDRS
include/OFApp.hpp
)

set (SRCS
src/OFApp.cpp
)

add_executable(lutFilterExample src/main.cpp ${SRCS})
target_link_libraries(lutFilterExample ${OF_LIBS})
