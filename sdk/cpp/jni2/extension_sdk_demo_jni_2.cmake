add_library(
        extension_sdk_demo_jni_2
        SHARED
        jni2/extension_sdk_demo_jni_2_api.cpp
        jni2/extension_sdk_demo_jni_2.cpp
        jni2/extension_sdk_demo_jni_2_listener.cpp
)
target_include_directories(extension_sdk_demo_jni_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/jni2)
target_include_directories(extension_sdk_demo_jni_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)
target_link_libraries(
        extension_sdk_demo_jni_2
        PRIVATE jni_helper
        ${log-lib} )