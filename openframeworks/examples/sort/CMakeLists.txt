include_directories(include)

set (HDRS
include/Application.hpp
include/Color.hpp
)

set (SRCS
src/Application.cpp
src/Color.cpp
)

add_executable(sort src/main.cpp ${SRCS})
target_link_libraries(sort ${OF_LIBS})
