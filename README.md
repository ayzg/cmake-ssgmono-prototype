# SSG-Mono CMake Module : Working Prototype & Usage Example

## Brief
Initial working prototype and basic example project for 'ssg-mono', a CMake module for managing monorepo CMake projects.

## Purpose
Eventually, any big project will need to separate concerns into smalled subproject.
I created this for the **C& Compiler**, a huge project which required separating into multiple subprojects - 
or else it would be unamanagable. 

While CMake advertises support for such a structure, setting it up and getting every
detail correct is a non-trivial task. Much of the work includes properly setting up a configure file for a package so
that find_package actually finds it. The next issue is figuring out how to make a local project which is built as
part of the current build be available and take advantage of find_package's dependency managment. Building and installing
an external project then using find_package is easy, but doing so for a local project is again - not so simple.
A lot of effort went into reading CMake documentation and examples to amalgamate all the bits and pieces of info
together to make this work. I don't expect myself or any CMake dev to remember how to set this on the fly.


## Details
`ssg-mono` is a CMake module for managing monorepo style CMake projects. 

The key features of `ssg-mono` are:
- Ability to have multiple inter-dependant projects controlled and compiled by a single CMake superproject. 
  You are able to compile subprojects and only depended on subproject without context switching IDE instances.
- Each sub-project may gain access to other subprojects through `find_package`, handling recursive dependencies.
- Each subproject is built and brought into the super-project using `FetchContent` internally; 
  this means all the output is neatly organized by CMake into build and sub-build folders for you.
- Works well with `find_package` of external dependencies, allowing you to handle both with the same `find_package`
  api. Extracting a sub project into an external dependency is easy due to not having to change the superproject CMakeLists.txt.

