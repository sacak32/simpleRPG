# Initialize project
cmake_minimum_required(VERSION 3.15)
project(simpleRPG VERSION 1.0 LANGUAGES CXX)

# Minimum CXX version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put all executables in bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Testing
enable_testing()
find_package(GTest REQUIRED)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)