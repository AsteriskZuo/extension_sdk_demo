//
// Created by 佐玉 on 2022/2/24.
//

#include "extension_sdk_demo_jni_listener_1.h"
#include <string>
#include "jni_helper.h"

jclass jclsGAppListener = 0;
jmethodID jclsGAppListener_adapterNativeHelloEcho = 0;
jmethodID jclsGAppListener_adapterNativeSendMessageEcho = 0;
jmethodID jclsGAppListener_adapterNativeSendMessageWithJsonEcho = 0;
jmethodID jclsGAppListener_adapterNativeSendMessageWithPBEcho = 0;

ExtensionSdkDemoAdapterJNIListener1::ExtensionSdkDemoAdapterJNIListener1(jobject listener)
        : _listener(listener) {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jclass jclsAppConnectStatusListener = env->FindClass(
            "com/example/extension_sdk_demo/ExtensionSdkDemoAdapterJNIListener1");
    if (env->ExceptionCheck() && 0 == jclsAppConnectStatusListener) {
        env->Throw(env->ExceptionOccurred());
    }
    jclsGAppListener = (jclass) env->NewGlobalRef(jclsAppConnectStatusListener);
    env->DeleteLocalRef(jclsAppConnectStatusListener);
    jclsAppConnectStatusListener = 0;
    jclsGAppListener_adapterNativeHelloEcho = env->GetMethodID(jclsGAppListener,
                                                               "adapterNativeHelloEcho", "()V");
    jclsGAppListener_adapterNativeSendMessageEcho = env->GetMethodID(jclsGAppListener,
                                                                     "adapterNativeSendMessageEcho",
                                                                     "(ILjava/lang/String;)V");
    jclsGAppListener_adapterNativeSendMessageWithJsonEcho = env->GetMethodID(jclsGAppListener,
                                                                             "adapterNativeSendMessageWithJsonEcho",
                                                                             "(ILjava/lang/String;)V");
    jclsGAppListener_adapterNativeSendMessageWithPBEcho = env->GetMethodID(jclsGAppListener,
                                                                           "adapterNativeSendMessageWithPBEcho",
                                                                           "(I[B)V");
}

ExtensionSdkDemoAdapterJNIListener1::~ExtensionSdkDemoAdapterJNIListener1() {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    if (jclsGAppListener)
        env->DeleteGlobalRef(jclsGAppListener);
    jclsGAppListener = 0;
    jclsGAppListener_adapterNativeHelloEcho = 0;
    jclsGAppListener_adapterNativeSendMessageEcho = 0;
    jclsGAppListener_adapterNativeSendMessageWithJsonEcho = 0;
    jclsGAppListener_adapterNativeSendMessageWithPBEcho = 0;
}

void ExtensionSdkDemoAdapterJNIListener1::adapterNativeHelloEcho() {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    env->CallVoidMethod(_listener, jclsGAppListener_adapterNativeHelloEcho);
}

void
ExtensionSdkDemoAdapterJNIListener1::adapterNativeSendMessageEcho(int number, std::string string) {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jstring jstring1 = env->NewStringUTF(string.c_str());
    env->CallVoidMethod(_listener, jclsGAppListener_adapterNativeSendMessageEcho, (jint) number,
                        jstring1);
    env->DeleteLocalRef(jstring1);
}

void ExtensionSdkDemoAdapterJNIListener1::adapterNativeSendMessageWithJsonEcho(int number,
                                                                               std::string json) {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jstring jjson = env->NewStringUTF(json.c_str());
    env->CallVoidMethod(_listener, jclsGAppListener_adapterNativeSendMessageWithJsonEcho, (jint) number,
                        jjson);
    env->DeleteLocalRef(jjson);
}

void
ExtensionSdkDemoAdapterJNIListener1::adapterNativeSendMessageWithPBEcho(int number, char *bytes,
                                                                        int bytes_size) {
    // todo:
}