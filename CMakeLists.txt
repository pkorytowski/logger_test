cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(logger)
include_directories(spdlog/include)
add_executable(app main.cpp)
set(OUTPUT_FILE_NAME app)
set(LIBSRC main.cpp)
add_library(logger ${LIBSRC})

target_link_libraries(${OUTPUT_FILE_NAME} logger)

set(CMAKE_CXX_FLAGS "-Wall -g --pedantic")
add_custom_target(check valgrind ./${OUTPUT_FILE_NAME})
add_custom_target(run ./${OUTPUT_FILE_NAME})

add_subdirectory(spdlog)

install(TARGETS ${OUTPUT_FILE_NAME} DESTINATION bin)
