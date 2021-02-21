cmake_minimum_required(VERSION 3.17)
project(cube C)

set(CMAKE_C_STANDARD 11)

add_executable(cube main.c)


target_link_libraries(cube raylib)
target_link_libraries(cube GL)
target_link_libraries(cube m)
target_link_libraries(cube pthread)
target_link_libraries(cube dl)
target_link_libraries(cube rt)
target_link_libraries(cube X11)