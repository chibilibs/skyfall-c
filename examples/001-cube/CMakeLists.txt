cmake_minimum_required (VERSION 3.25)

project(001-cube)

add_executable(${PROJECT_NAME} src/main.c)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/../../include
)

target_link_libraries(${PROJECT_NAME}
    skyfall
)
