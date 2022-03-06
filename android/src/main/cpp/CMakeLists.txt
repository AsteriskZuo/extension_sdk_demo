
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("extension_sdk_demo")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../../../sdk/cpp ${CMAKE_CURRENT_SOURCE_DIR}/../../../../sdk/cpp/build)

#include(${CMAKE_CURRENT_SOURCE_DIR}/../../../../sdk/cpp/extension_sdk_demo.cmake)
