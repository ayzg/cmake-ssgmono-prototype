cmake_minimum_required (VERSION 3.8)
project ("project_b" LANGUAGES C CXX)
include(SsgProjectBase)
SsgProjectBase_Prelude()

# Import the project_a library through 'find_package'.
find_package(project_a REQUIRED CONFIG)

# Create an interface library b.
set(LIBRARY_B_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_library(library_b INTERFACE)
target_include_directories(library_b INTERFACE "${LIBRARY_B_HEADERS_DIR}")
target_sources(library_b INTERFACE "${LIBRARY_B_HEADERS_DIR}/library_b.hpp")

# link the library_a to the exported library_b.
add_dependencies(library_b library_a)
target_link_libraries(library_b INTERFACE library_a)

# Export local subproject configuration files.
get_directory_property(PROJECT_B_CONFIG_INPUT_FILE_PATH DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} SSG_PROJECT_EXPORT_DIR)
string(APPEND PROJECT_B_CONFIG_INPUT_FILE_PATH "/config.cmake.in")
SsgProjectBase_ExportLocalConfigFile("${PROJECT_B_CONFIG_INPUT_FILE_PATH}") # todo: autogenerate if no input provided.