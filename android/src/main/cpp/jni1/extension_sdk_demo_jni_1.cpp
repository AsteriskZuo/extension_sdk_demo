//
// Created by asterisk on 2022/2/24.
//

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <string>
#include <memory>
#include <iostream>
#include "extension_sdk_demo_jni_listener_1.h"
#include "extension_sdk_demo_cpp_wrapper.h"
/* Header for class com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1 */

#ifndef _Included_com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
#define _Included_com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
 * Method:    adapterNativeHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNI1_adapterNativeHello
        (JNIEnv *env, jobject listener) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_hello();
}

/*
 * Class:     com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
 * Method:    adapterNativeSendMessage
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNI1_adapterNativeSendMessage
        (JNIEnv *env, jobject, jint number, jstring string) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    const char *cstrString = (string ? env->GetStringUTFChars(string, 0) : nullptr);
    std::string cppString = std::string(cstrString);
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message(number, cstrString);
    if (string) env->ReleaseStringUTFChars(string, cstrString);
    env->DeleteLocalRef(string);
}

/*
 * Class:     com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
 * Method:    adapterNativeSendMessageWithJson
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNI1_adapterNativeSendMessageWithJson
        (JNIEnv *env, jobject, jint number, jstring json) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    const char *cstrJson = (json ? env->GetStringUTFChars(json, 0) : nullptr);
    std::string cppJson = std::string(cstrJson);
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message_with_json(number, cstrJson);
    if (json) env->ReleaseStringUTFChars(json, cstrJson);
    env->DeleteLocalRef(json);
}

/*
 * Class:     com_example_extension_sdk_demo_ExtensionSdkDemoAdapterJNI1
 * Method:    adapterNativeSendMessageWithPB
 * Signature: (I[B)V
 */
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNI1_adapterNativeSendMessageWithPB
        (JNIEnv *env, jobject, jint number, jbyteArray pb) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    // TODO:
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_ExtensionSdkDemoAdapterJNI1_adapterNativeInit(JNIEnv *env,
                                                                                    jobject thiz,
                                                                                    jobject listener) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    jobject listenerRef = env->NewGlobalRef(listener);
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> cpp_listener = std::make_shared<ExtensionSdkDemoAdapterJNIListener1>(
            listenerRef);
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_init(cpp_listener);
}

#ifdef __cplusplus
}
#endif
#endif

