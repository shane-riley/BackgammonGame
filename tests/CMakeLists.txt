include(FetchContent)

# CMake 3.24+: give extracted files the extraction time so rebuilds work correctly
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
# Prevent GoogleTest from overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

list(TRANSFORM BACKGAMMON_SOURCES PREPEND ${PROJECT_SOURCE_DIR}/)

add_executable(backgammon_tests
    version_test.cpp
    ${BACKGAMMON_SOURCES}
)
target_include_directories(backgammon_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_options(backgammon_tests PRIVATE ${BACKGAMMON_WARNINGS})
target_link_libraries(backgammon_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(backgammon_tests)
