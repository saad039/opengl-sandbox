cmake_minimum_required(VERSION 3.15)

project(cg-sandbox VERSION 1.0.0 LANGUAGES CXX C)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
endif()

add_library(project_warnings INTERFACE)


include(cmake/Cache.cmake)

include(cmake/Linker.cmake)
configure_linker(project_options)


include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)


include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)


option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
  target_precompile_headers(
    project_options
    INTERFACE
    <vector>
    <string>
    <map>
    <unordered_map>
    <memory>
    <functional>
    <chrono>
    <algorithm>
    <utility>)
endif()

add_subdirectory(glad)
add_subdirectory(glfw)


include_directories(include)
file(GLOB SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(sandbox ${SRC_FILES})

target_link_libraries(sandbox 
                      PRIVATE glad  
                      PRIVATE glfw)