cmake_minimum_required(VERSION 3.16.0)

project(CxxTemplate
  VERSION 0.1.0.0
  LANGUAGES CXX
  DESCRIPTION "A Test Driven Example from Modern C++ Programming with Test-Driven Development"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_DEBUG_POSTFIX d)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

find_package(GTest)
if(GTEST_FOUND)
set(Gtest_FOUND TRUE)
endif()
if(GTest_FOUND)
include(GoogleTest)
endif()
enable_testing()
add_subdirectory(tests)

include(CheckIncludeFiles)
CHECK_INCLUDE_FILES(sys/prctl.h HAVE_SYS_PRCTL_H)

add_executable(run
  src/main.cpp
  src/Soundex.cpp
)

include(FeatureSummary)
feature_summary(WHAT ALL)

# include(DumpProps)
# print_target_properties(diva)
# include(DumpVariables)
# dump_all_variables()
