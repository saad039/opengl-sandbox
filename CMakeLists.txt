cmake_minimum_required(VERSION 3.17)

project(cg-sandbox VERSION 1.0.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)

add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(glad)
add_subdirectory(glfw)
set(BUILD_SHARED_LIBS OFF)


include_directories(include)
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")


add_executable(sandbox ${SRC_FILES})

target_link_libraries(sandbox 
                      PRIVATE glad  
                      PRIVATE glfw )