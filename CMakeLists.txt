cmake_minimum_required(VERSION 3.20)
project(Lab4 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(geometric_figures INTERFACE)
target_include_directories(geometric_figures INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_features(geometric_figures INTERFACE cxx_std_20)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
          googletest
          GIT_REPOSITORY https://github.com/google/googletest.git
          GIT_TAG release-1.14.0
  )
  FetchContent_MakeAvailable(googletest)
endif()

add_executable(Lab4 src/main.cpp)
target_link_libraries(Lab4 PRIVATE geometric_figures)

enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")
if(TEST_SOURCES)
  add_executable(Lab4_tests ${TEST_SOURCES})
  target_link_libraries(Lab4_tests PRIVATE
          GTest::gtest
          GTest::gtest_main
          geometric_figures
  )
  gtest_discover_tests(Lab4_tests)
endif()