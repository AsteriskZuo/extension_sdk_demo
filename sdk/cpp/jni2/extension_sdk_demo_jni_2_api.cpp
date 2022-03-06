//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_jni_2_api.h"
#include "jni_helper.h"
#include <iostream>

jclass jclsGAppApi = 0;
jmethodID jclsGAppApi_getInstance = 0;
jmethodID jclsGAppApi_adapterNativeInit = 0;
jmethodID jclsGAppApi_adapterNativeHello = 0;
jmethodID jclsGAppApi_adapterNativeSendMessage = 0;
jmethodID jclsGAppApi_adapterNativeSendMessageWithJson = 0;
jmethodID jclsGAppApi_adapterNativeSendMessageWithPB = 0;

jclass jclsGListener2 = 0;
jmethodID jclsGListener2_constructor = 0;

extension_sdk_demo_jni_2_api extension_sdk_demo_jni_2_api::instance;

void extension_sdk_demo_jni_2_api::init() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jclass jclsAppApi = env->FindClass(
            "com/example/extension_sdk_demo/ExtensionSdkDemoAdapterJNI2");
    if (env->ExceptionCheck() && 0 == jclsAppApi) {
        env->Throw(env->ExceptionOccurred());
    }
    jclsGAppApi = (jclass) env->NewGlobalRef(jclsAppApi);
    env->DeleteLocalRef(jclsAppApi);
    jclsAppApi = 0;
    jclsGAppApi_getInstance = env->GetStaticMethodID(jclsGAppApi,
                                                     "getInstance",
                                                     "()Lcom/example/extension_sdk_demo/ExtensionSdkDemoAdapterJNI2;");
    jclsGAppApi_adapterNativeInit = env->GetMethodID(jclsGAppApi, "adapterNativeInit",
                                                     "(Lcom/example/extension_sdk_demo/ExtensionSdkDemoAdapterJNIListener2;)V");
    jclsGAppApi_adapterNativeHello = env->GetMethodID(jclsGAppApi, "adapterNativeHello", "()V");
    jclsGAppApi_adapterNativeSendMessage = env->GetMethodID(jclsGAppApi, "adapterNativeSendMessage",
                                                            "(ILjava/lang/String;)V");
    jclsGAppApi_adapterNativeSendMessageWithJson = env->GetMethodID(jclsGAppApi,
                                                                    "adapterNativeSendMessageWithJson",
                                                                    "(ILjava/lang/String;)V");
    jclsGAppApi_adapterNativeSendMessageWithPB = env->GetMethodID(jclsGAppApi,
                                                                  "adapterNativeSendMessageWithPB",
                                                                  "(I[B)V");


    jclass jclsListener2 = env->FindClass(
            "com/example/extension_sdk_demo/ExtensionSdkDemoAdapterJNIListener2");
    if (env->ExceptionCheck() && 0 == jclsListener2) {
        env->Throw(env->ExceptionOccurred());
    }
    jclsGListener2 = (jclass) env->NewGlobalRef(jclsListener2);
    env->DeleteLocalRef(jclsListener2);
    jclsListener2 = 0;

    jclsGListener2_constructor = env->GetMethodID(jclsGListener2, "<init>", "()V");
}

void extension_sdk_demo_jni_2_api::uninit() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    if (jclsGAppApi)
        env->DeleteGlobalRef(jclsGAppApi);
    jclsGAppApi_getInstance = 0;
    jclsGAppApi_adapterNativeInit = 0;
    jclsGAppApi_adapterNativeHello = 0;
    jclsGAppApi_adapterNativeSendMessage = 0;
    jclsGAppApi_adapterNativeSendMessageWithJson = 0;
    jclsGAppApi_adapterNativeSendMessageWithPB = 0;

    if (jclsGListener2)
        env->DeleteGlobalRef(jclsGListener2);
    jclsGListener2_constructor = 0;
}


extension_sdk_demo_jni_2_api::extension_sdk_demo_jni_2_api() {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;

}

extension_sdk_demo_jni_2_api::~extension_sdk_demo_jni_2_api() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
}

void extension_sdk_demo_jni_2_api::adapterNativeInit(
        std::shared_ptr<ExtensionSdkDemoAdapterJNIListener2> listener2) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    // todo: jni部分 创建静态单实例java对象
    this->_listener = listener2;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jobject api = env->CallStaticObjectMethod(jclsGAppApi, jclsGAppApi_getInstance);
    jobject jclsGListener2_object = env->NewObject(jclsGListener2, jclsGListener2_constructor);
    env->CallVoidMethod(api, jclsGAppApi_adapterNativeInit, jclsGListener2_object);
}

void extension_sdk_demo_jni_2_api::adapterNativeHello() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    // todo: jni部分
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jobject api = env->CallStaticObjectMethod(jclsGAppApi, jclsGAppApi_getInstance);
    env->CallVoidMethod(api, jclsGAppApi_adapterNativeHello);
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessage(int number, std::string string) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    // todo: jni部分
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jobject api = env->CallStaticObjectMethod(jclsGAppApi, jclsGAppApi_getInstance);
    jstring str = env->NewStringUTF(string.c_str());
    env->CallVoidMethod(api, jclsGAppApi_adapterNativeSendMessage, (jint) number, str);
    env->DeleteLocalRef(str);
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithJson(int number, std::string json) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
// todo: jni部分
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jobject api = env->CallStaticObjectMethod(jclsGAppApi, jclsGAppApi_getInstance);
    jstring str = env->NewStringUTF(json.c_str());
    env->CallVoidMethod(api, jclsGAppApi_adapterNativeSendMessageWithJson, (jint) number, str);
    env->DeleteLocalRef(str);
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithPB(int number, std::string bytes) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
// todo: jni部分
}

void extension_sdk_demo_jni_2_api::adapterNativeHelloEcho() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    this->_listener->adapterNativeHelloEcho();
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageEcho(int number, std::string string) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    this->_listener->adapterNativeSendMessageEcho(number, string);
}

void
extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithJsonEcho(int number, std::string json) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    this->_listener->adapterNativeSendMessageWithJsonEcho(number, json);
}

void
extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithPBEcho(int number, std::string bytes) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    const char *s = bytes.c_str();
    this->_listener->adapterNativeSendMessageWithPBEcho(number, const_cast<char *>(s),
                                                        bytes.length());
}
