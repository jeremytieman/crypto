find_package(Catch2 3 QUIET)

if(NOT Catch2_FOUND)
  Include(FetchContent)
  set(CMAKE_CXX_FLAGS "-Wno-everything")

  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.0-preview3
  )

  FetchContent_MakeAvailable(Catch2)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
endif()

add_executable(cryptoTest main.cpp)

target_link_libraries(cryptoTest PRIVATE Catch2::Catch2WithMain)
target_include_directories(cryptoTest PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
set_target_properties(cryptoTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/test/)

add_test(NAME allTests COMMAND cryptoTest)
