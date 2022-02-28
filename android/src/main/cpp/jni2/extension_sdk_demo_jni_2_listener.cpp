//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_jni_2_listener.h"
#include "extension_sdk_demo_jni_2_api.h"
#include <iostream>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeHelloEcho(
        JNIEnv *env, jobject thiz) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHelloEcho();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageEcho(
        JNIEnv *env, jobject thiz, jint number, jstring string) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    const char *cstrString = (string ? env->GetStringUTFChars(string, 0) : nullptr);
    std::string cppString = std::string(cstrString);
    if (string) env->ReleaseStringUTFChars(string, cstrString);
    env->DeleteLocalRef(string);
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageEcho(number, cppString);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageWithJsonEcho(
        JNIEnv *env, jobject thiz, jint number, jstring json) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    const char *cstrString = (json ? env->GetStringUTFChars(json, 0) : nullptr);
    std::string cppString = std::string(cstrString);
    if (json) env->ReleaseStringUTFChars(json, cstrString);
    env->DeleteLocalRef(json);
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithJsonEcho(number, cppString);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNIListener2_nativeSendMessageWithPBEcho(
        JNIEnv *env, jobject thiz, jint number, jbyteArray bytes) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithPBEcho(number, "");
}