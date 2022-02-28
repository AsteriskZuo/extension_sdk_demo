add_library(
        extension_sdk_demo_wrapper
        SHARED
        wrapper/extension_sdk_demo_c_wrapper.c
        wrapper/extension_sdk_demo_cpp_wrapper.cpp
)
target_include_directories(extension_sdk_demo_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)
target_include_directories(extension_sdk_demo_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jni1)
target_include_directories(extension_sdk_demo_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jni2)
target_link_libraries(
        extension_sdk_demo_wrapper
        PUBLIC extension_sdk_demo_jni_1
        PUBLIC extension_sdk_demo_jni_2
        ${log-lib} )