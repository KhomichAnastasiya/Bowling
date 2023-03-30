cmake_minimum_required(VERSION 3.23.2)

project(bowling)

file(GLOB_RECURSE SRC source/*.cpp)
file(GLOB_RECURSE HDR include/*.h)

set(LIB "library/nlohmann/include")

include_directories(include ${LIB})

add_executable(bowling ${SRC} ${HDR})

target_link_libraries(bowling)