cmake_minimum_required( VERSION 3.0 )
project(mud)

find_package( Boost COMPONENTS system REQUIRED )
find_package( Threads )

include_directories( ${Boost_INCLUDE_DIR} . )

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wreturn-type -Wreorder -Wall)
set(SRCS
    src/main.cpp
    src/Server/Connection.cpp
    src/Server/LineOrientedConnection.cpp
)

add_executable(mud ${SRCS})
target_link_libraries(mud LINK_PUBLIC ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
