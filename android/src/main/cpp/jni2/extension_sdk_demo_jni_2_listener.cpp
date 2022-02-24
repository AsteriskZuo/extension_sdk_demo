//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_jni_2_listener.h"
#include "extension_sdk_demo_jni_2_api.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeHelloEcho(
        JNIEnv *env, jobject thiz) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHelloEcho();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageEcho(
        JNIEnv *env, jobject thiz, jint number, jstring string) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHelloEcho();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageWithJsonEcho(
        JNIEnv *env, jobject thiz, jint number, jstring json) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHelloEcho();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageWithPBEcho(
        JNIEnv *env, jobject thiz, jint number, jbyteArray bytes) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHelloEcho();
}
