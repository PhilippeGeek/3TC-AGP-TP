cmake_minimum_required(VERSION 3.3)
project(3TC_AGP_TP)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(EXECUTABLE_OUTPUT_PATH build/${CMAKE_BUILD_TYPE})

# Uncomment the following lines to link math library
#if(UNIX)
#    link_libraries(m)
#endif(UNIX)

file(
        GLOB_RECURSE
        tp1
        TP1/src/*
)

add_executable(
        tp1.out
        ${tp1}
)

file(
        GLOB_RECURSE
        tp2
        TP2/src/*
)

add_executable(
        tp2.out
        ${tp2}
)

file(
        GLOB_RECURSE
        td5
        TD5/*
)

add_executable(
        td5.out
        ${td5}
)