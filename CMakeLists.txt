cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
#if (POLICY CMP0141)
#  cmake_policy(SET CMP0141 NEW)
#  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
#endif()

project(SuperbuildTests
	VERSION 0.0.0.0
	DESCRIPTION "SSG Company Monorepo"
	HOMEPAGE_URL "www.acpp.dev"
	LANGUAGES C CXX	
)

# Source directory containing this monorepo's local packages.
set(SSGMONOREPO_LOCAL_PROJECTS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/projects")

# Manually add 'ssgmono_project', SSG monorepo configuration package.
#
# Afterwards use the SsgProjectPackageUtils module function:
#   'SsgProjectBase_DeclareSubproject(<projectName> SOURCE_DIR [path])'
# to add subprojects in this project.
#
# Other top-level projects should use 'find_package(ssgmonorepo_project)' instead,
# when using the 'ssgmonorepo_project' project as an external project.
include(FetchContent)
FetchContent_Declare(ssgmono_project 
  SOURCE_DIR "${SSGMONOREPO_LOCAL_PROJECTS_SOURCE_DIR}/ssgmono_project" 
  OVERRIDE_FIND_PACKAGE
)
find_package(ssgmono_project REQUIRED CONFIG)

# Declare all other subprojects here:

ssg_declare_subproject(project_a SOURCE_DIR "${SSGMONOREPO_LOCAL_PROJECTS_SOURCE_DIR}/project_a")

#ssg_declare_subproject(project_b SOURCE_DIR "${SSGMONOREPO_LOCAL_PROJECTS_SOURCE_DIR}/project_b")

#ssg_declare_subproject(project_c SOURCE_DIR "${SSGMONOREPO_LOCAL_PROJECTS_SOURCE_DIR}/project_c")

#FetchContent_MakeAvailable(project_a)
#set(project_a_SOURCE_DIR "${project_a_SOURCE_DIR}")
#set(project_a_BINARY_DIR "${project_a_BINARY_DIR}")
#add_subdirectory("${project_a_SOURCE_DIR}")

#FetchContent_MakeAvailable(project_a)

#set(project_a_DIR "${SSGPKG_PROJECT_A_IMPORT_DIR}")
find_package(project_a REQUIRED CONFIG)

#add_subdirectory("${SSGPKG_LOCAL_PROJECTS_SOURCE_DIR}/project_a")
#add_subdirectory("${SSGPKG_LOCAL_PROJECTS_SOURCE_DIR}/project_b")
#add_subdirectory("${SSGPKG_LOCAL_PROJECTS_SOURCE_DIR}/project_c")

#[============================================================================[
Copyright 2025 Anton Yashchenko
Licensed under the Apache License, Version 2.0(the "License");
===============================================================================
@project: [MTA] Meta Template Archive
@author(s): Anton Yashchenko
@website: https://www.acpp.dev
#]============================================================================]