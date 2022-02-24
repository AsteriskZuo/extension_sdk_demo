add_library(
        extension_sdk_demo_jni_1
        STATIC
        jni1/extension_sdk_demo_jni_1.cpp )
target_link_libraries(
        extension_sdk_demo_jni_1
        ${log-lib} )