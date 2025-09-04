cmake_minimum_required (VERSION 3.8)
project ("project_a" LANGUAGES C CXX)

find_package(ssgmono_project REQUIRED CONFIG)

include(SsgProjectBase)
ssg_setup_standard_project_vars()

# Create a static library a.
set(LIBRARY_A_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(LIBRARY_A_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(library_a "${LIBRARY_A_SOURCES_DIR}/library_a.cpp")
target_include_directories(library_a PUBLIC "${LIBRARY_A_HEADERS_DIR}")
target_sources(library_a PUBLIC "${LIBRARY_A_HEADERS_DIR}/library_a.hpp")

# Export local subproject configuration files.
get_directory_property(PROJECT_A_PROJECT_EXPORT_DIR SSG_PROJECT_EXPORT_DIR)
get_directory_property(PROJECT_A_PROJECT_IMPORT_DIR SSG_PROJECT_IMPORT_DIR)

ssg_configure_alias_targets_file(
    TARGETS library_a
    PREFIX project_a
    OUTPUT_FILE_PATH "${PROJECT_A_PROJECT_IMPORT_DIR}/${PROJECT_NAME}-subproject-targets.cmake"
    INPUT_FILE_PATH "${PROJECT_A_PROJECT_EXPORT_DIR}/subproject-targets.cmake.in"
)

ssg_export_subproject_config(project_a 
  CONFIG_SUBPROJECT "${PROJECT_A_PROJECT_EXPORT_DIR}/subproject-config.cmake.in"
  OUTPUT_DIR "${PROJECT_A_PROJECT_IMPORT_DIR}"
) 
