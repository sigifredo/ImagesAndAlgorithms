include_directories(include)

set (HDRS
include/OFApp.hpp
)

set (SRCS
src/OFApp.cpp
)

add_executable(floatingPointImageExample src/main.cpp ${SRCS})
target_link_libraries(floatingPointImageExample ${OF_LIBS})
