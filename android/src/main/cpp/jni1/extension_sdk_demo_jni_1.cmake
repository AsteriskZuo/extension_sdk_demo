add_library(
        extension_sdk_demo_jni_1
        SHARED
        jni1/extension_sdk_demo_jni_1.cpp
        jni1/extension_sdk_demo_jni_listener_1.cpp
)
target_include_directories(extension_sdk_demo_jni_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jni1)
target_include_directories(extension_sdk_demo_jni_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)
target_link_libraries(
        extension_sdk_demo_jni_1
        PRIVATE jni_helper
        ${log-lib} )