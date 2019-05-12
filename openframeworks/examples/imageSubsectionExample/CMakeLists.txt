include_directories(include)

set (HDRS
include/OFApp.hpp
)

set (SRCS
src/OFApp.cpp
)

add_executable(imageSubsectionExample src/main.cpp ${SRCS})
target_link_libraries(imageSubsectionExample ${OF_LIBS})
