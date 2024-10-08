cmake_minimum_required(VERSION 3.14)
project(MyVector)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# -------------------- Library setup
include_directories(include)
add_library(my_vector src/my_vector.cpp)


# -------------------- Testing
enable_testing()

add_executable(run_unit_tests test/my_vector.cpp test/my_vector_resize.cpp)
target_link_libraries(run_unit_tests GTest::gtest_main my_vector)

include(GoogleTest)
gtest_discover_tests(run_unit_tests)
