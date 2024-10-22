cmake_minimum_required(VERSION 3.15...3.30)

project(
  A_MerchantsQuest 
  VERSION 1.0.0
  DESCRIPTION "My Logic Formulation and Introductory Programming (CCIPROG1) machine program project." 
  LANGUAGES C CXX)

set(HEADER_DIR "../include")
set(C_FLAGS "-Wall" "-Wextra" "-Wpedantic")
set(CXX_FLAGS "-Wall" "-Wextra" "-Wpedantic")
set(C_STD "c_std_99")
set(CXX_STD "cxx_std_14")

add_subdirectory(libs)
add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(WORKING_DIRECTORY .)

  include(FetchContent)

  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
  )

  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(googletest)

  include(CTest)

  enable_testing()

  add_subdirectory(tests)
endif()
