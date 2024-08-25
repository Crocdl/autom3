cmake_minimum_required(VERSION 3.27)
project(lab3)
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic -g)
flex_target(lexer F.l "${CMAKE_CURRENT_BINARY_DIR}/F.cc")
#bison_target(parser B.y "${CMAKE_CURRENT_BINARY_DIR}/B.cc")
BISON_TARGET(parser B.y ${CMAKE_CURRENT_BINARY_DIR}/B.cc
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/B.hh)
add_library(lib STATIC
        ${sources}
        "${CMAKE_CURRENT_BINARY_DIR}/F.cc"
        "${CMAKE_CURRENT_BINARY_DIR}/B.cc"
)
add_flex_bison_dependency(lexer parser)
add_subdirectory(map)
add_subdirectory(robot)
add_subdirectory(ast)
add_executable(lab3 ${BISON_parser_OUTPUTS})
target_link_libraries(lab3 robot)
target_link_libraries(lab3 ast)
target_link_libraries(lab3 map)
target_link_libraries(lab3 lib)
