
# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("extension_sdk_demo")

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(JNI1_SOURCE_FILES
        jni1/extension_sdk_demo_jni_1.cpp
        jni1/extension_sdk_demo_jni_listener_1.cpp
)
set(JNI1_HEADER_FILES
        jni1/extension_sdk_demo_jni_listener_1.h
)
set(JNI2_SOURCE_FILES
        jni2/extension_sdk_demo_jni_2_api.cpp
        jni2/extension_sdk_demo_jni_2.cpp
        jni2/extension_sdk_demo_jni_2_listener.cpp
)
set(JNI2_HEADER_FILES
        jni2/extension_sdk_demo_jni_2_api.h
        jni2/extension_sdk_demo_jni_2_listener.h
)
set(WRAPPER_SOURCE_FILES
        wrapper/extension_sdk_demo_cpp_wrapper.cpp
)
set(WRAPPER_HEADER_FILES
        wrapper/extension_sdk_demo_cpp_wrapper.h
)
set(JNI_SOURCE_FILES
        jni/jni_helper.cpp
)
set(JNI_HEADER_FILES
        jni/jni_helper.h
)

#add_library(
#        jni_helper
#        jni/jni_helper.cpp
#)
#target_include_directories(jni_helper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jni)
#target_link_libraries(
#        jni_helper
#        ${log-lib}
#)

#include(jni1/extension_sdk_demo_jni_1.cmake)
#include(jni2/extension_sdk_demo_jni_2.cmake)
#include(wrapper/extension_sdk_demo_wrapper.cmake)

add_library( # Sets the name of the library.
             extension_sdk_demo

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             extension_sdk_demo.cpp
        ${JNI1_SOURCE_FILES}
        ${JNI2_SOURCE_FILES}
        ${WRAPPER_SOURCE_FILES}
        ${JNI_SOURCE_FILES}
)
#target_include_directories(
#        extension_sdk_demo
#        PRIVATE ${JNI1_HEADER_FILES}
#        PRIVATE ${JNI2_HEADER_FILES}
#        PRIVATE ${JNI_HEADER_FILES}
#        PRIVATE ${WRAPPER_HEADER_FILES}
#)
target_include_directories(extension_sdk_demo
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/jni
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/jni1
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/jni2
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/wrapper
        )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       extension_sdk_demo
#        PRIVATE jni_helper
#        PUBLIC extension_sdk_demo_jni_1
#        PUBLIC extension_sdk_demo_jni_2
#        PRIVATE extension_sdk_demo_wrapper

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )


#add_subdirectory(jni1)
#add_subdirectory(jni2)

