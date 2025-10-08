cmake_minimum_required(VERSION 3.20)
project(EarthDayBattle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/git.cmake)
include(cmake/spdlog.cmake)
include(cmake/sfml.cmake)
include(cmake/assets.cmake)

set(ENGINE_SRC
    src/engine/engine.cpp
    src/engine/scene.cpp
    src/engine/scene_manager.cpp
)
set(GAME_SRC
    src/main.cpp
    src/fighter.cpp
    src/action.cpp
)
set(SRC ${ENGINE_SRC} ${GAME_SRC})

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
        spdlog::spdlog
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        GIT_HASH="${GIT_HASH}"
)

add_dependencies(${PROJECT_NAME} copy_assets)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WINDOWS)
elseif(UNIX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_LINUX)
endif()
