cmake_minimum_required(VERSION 3.5)

project(baz LANGUAGES CXX VERSION 0.0.1)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/_deps/catch2-src/single_include)
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mockcpp/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mockcpp/lib)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2 mockcpp)
