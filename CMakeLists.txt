cmake_minimum_required(VERSION 3.15)

project(RakPlugin)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

add_subdirectory(lib/raklite)

target_link_libraries(${PROJECT_NAME} PRIVATE
    raklite
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD "17"
    CXX_STANDARD_REQUIRED "YES"
)