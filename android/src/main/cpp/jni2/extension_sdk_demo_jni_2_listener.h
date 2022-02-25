//
// Created by 佐玉 on 2022/2/25.
//

#ifndef ANDROID_EXTENSION_SDK_DEMO_JNI_2_LISTENER_H
#define ANDROID_EXTENSION_SDK_DEMO_JNI_2_LISTENER_H

#include <jni.h>
#include <string>

// 通过继承原生SDK的接口获取通知，
class ExtensionSdkDemoAdapterJNIListener2 {
public:
    virtual void adapterNativeHelloEcho() = 0;

    virtual void adapterNativeSendMessageEcho(int number, std::string string) = 0;

    virtual void adapterNativeSendMessageWithJsonEcho(int number, std::string json) = 0;

    virtual void adapterNativeSendMessageWithPBEcho(int number, char* bytes, int bytes_size) = 0;

};

#endif //ANDROID_EXTENSION_SDK_DEMO_JNI_2_LISTENER_H
