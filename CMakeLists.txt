cmake_minimum_required(VERSION 3.25)

project(
    skyfall
    VERSION 0.0.1
    DESCRIPTION "WIP: 3D game engine written in C!"
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_C_FLAGS "-DLOG_USE_COLOR -Wall -Werror -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-parameter")

add_library(${PROJECT_NAME} STATIC 
    src/application.c

    src/core/init.c
    src/core/window.c

    src/log.c
    src/glad.c
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

add_subdirectory(examples)
