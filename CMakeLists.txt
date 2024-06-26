cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  main
  ./tests/test.cpp
  ./srcs/arithmetic.cpp
  ./srcs/determinant.cpp
  ./srcs/inverse.cpp
  ./srcs/complement.cpp
  ./srcs/transpose.cpp
  ./tools/print_matrix.cpp
  ./tools/GaussElimination.cpp
  ./tools/ResizeMatrix.cpp
)
target_link_libraries(
  main
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(main)
