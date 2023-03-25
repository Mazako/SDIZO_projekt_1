cmake_minimum_required(VERSION 3.24)
project(MAIN)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
add_executable(MAIN_RUN ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries( MAIN_RUN
        SDIZO_PROJ_1
)
