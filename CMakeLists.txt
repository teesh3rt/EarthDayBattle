cmake_minimum_required(VERSION 4.1.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyGame)

include(./cmake/git.cmake)
include(./cmake/sfml.cmake)

set(EXECUTABLE_NAME ${CMAKE_PROJECT_NAME})

add_executable(
    ${EXECUTABLE_NAME}
    ./src/main.cpp
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)

target_compile_definitions(
    ${EXECUTABLE_NAME}
    PRIVATE
    GIT_HASH="${GIT_HASH}"
)