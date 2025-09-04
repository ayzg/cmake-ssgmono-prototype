#[============================================================================[
Copyright 2025 Anton Yashchenko
Licensed under the Apache License, Version 2.0(the "License");
===============================================================================
@project: [ssgmono_project] SSG Monorepo Configuration Package
@author(s): Anton Yashchenko
@website: https://www.acpp.dev
===============================================================================
@file 
@ingroup
@brief 
#]============================================================================]
cmake_minimum_required (VERSION 3.8)

project(ssgmono_project
	VERSION 0.0.0.0
	DESCRIPTION "SSG Monorepo Configuration Project"
	HOMEPAGE_URL "www.acpp.dev"
	LANGUAGES C CXX	
)

# Add ssgmono scripts to cmake module path.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Other subprojects should use:
#		find_package(ssgmono_project REQUIRED CONFIG)
#		include(SsgProjectBase)
#		ssg_setup_standard_project_vars()
include(SsgProjectBase)
ssg_setup_standard_project_vars()

# Export scripts and find_package folder so other projects in the build may use them.
include(SsgProjectPackageUtils)
# Make these variables available in the following config call:
get_directory_property(SSGMONO_PROJECT_EXPORT_DIR SSG_PROJECT_EXPORT_DIR)
get_directory_property(SSGMONO_PROJECT_IMPORT_DIR SSG_PROJECT_IMPORT_DIR)
get_directory_property(SSGMONO_PROJECT_CMAKE_MODULES_DIR SSG_PROJECT_CMAKE_MODULES_DIR)
ssg_export_subproject_config(ssgmono_project
	CONFIG_SUBPROJECT "${SSGMONO_PROJECT_EXPORT_DIR}/subproject-config.cmake.in"
	# CONFIG "${SSGMONO_PROJECT_EXPORT_DIR}/config.cmake.in"
	OUTPUT_DIR "${SSGMONO_PROJECT_IMPORT_DIR}"
)



