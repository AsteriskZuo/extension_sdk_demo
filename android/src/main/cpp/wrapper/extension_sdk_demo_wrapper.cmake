add_library(
        extension_sdk_demo_wrapper
        STATIC
        wrapper/extension_sdk_demo_c_wrapper.c
        wrapper/extension_sdk_demo_cpp_wrapper.cpp
)
target_include_directories(extension_sdk_demo_wrapper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)
target_link_libraries(
        extension_sdk_demo_wrapper
        extension_sdk_demo_jni_1
        extension_sdk_demo_jni_2
        ${log-lib} )