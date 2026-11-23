# BackgammonGame

C++17 backgammon, built with CMake and tested with GoogleTest.

## Requirements

- CMake 3.16+ (3.21+ to use presets)
- A C++17 compiler (GCC 9+, Clang 10+, MSVC 2019+)
- Internet access on first configure (GoogleTest is fetched via `FetchContent`)

## Build and test

```sh
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
./build/debug/backgammon
```

Without presets:

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Pass `-DBACKGAMMON_BUILD_TESTS=OFF` to skip building tests.

New `.cpp` files (other than `main.cpp`) go in `BACKGAMMON_SOURCES` in the top-level `CMakeLists.txt` so both the game and the tests compile them.

## Layout

```
include/backgammon/   headers
src/                  sources (main.cpp is the entry point)
tests/                GoogleTest unit tests
```
