cmake_minimum_required (VERSION 3.8)
project ("project_c" LANGUAGES C CXX)
include(SsgProjectBase)
SsgProjectBase_Prelude()

find_package(project_a REQUIRED CONFIG)
find_package(project_b REQUIRED CONFIG)

set(EXECUTABLE_C_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(EXECUTABLE_C_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(executable_c "${EXECUTABLE_C_SOURCES_DIR}/main.cpp")

target_include_directories(executable_c PRIVATE "${EXECUTABLE_C_HEADERS_DIR}")
target_sources(executable_c PRIVATE "${EXECUTABLE_C_HEADERS_DIR}/project_headers.hpp")

# link the executable to the exported libraries.
add_dependencies(executable_c library_a library_b)
target_link_libraries(executable_c PRIVATE library_a library_b)

# Export local subproject configuration files.
get_directory_property(PROJECT_C_CONFIG_INPUT_FILE_PATH DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} SSG_PROJECT_EXPORT_DIR)
string(APPEND PROJECT_C_CONFIG_INPUT_FILE_PATH "/config.cmake.in")
SsgProjectBase_ExportLocalConfigFile("${PROJECT_C_CONFIG_INPUT_FILE_PATH}") # todo: autogenerate if no input provided.