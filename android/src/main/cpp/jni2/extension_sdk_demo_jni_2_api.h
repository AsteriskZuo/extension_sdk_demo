//
// Created by 佐玉 on 2022/2/25.
//

#ifndef ANDROID_EXTENSION_SDK_DEMO_JNI_2_API_H
#define ANDROID_EXTENSION_SDK_DEMO_JNI_2_API_H

#include <jni.h>
#include <string>
#include <memory>
#include "extension_sdk_demo_jni_2_listener.h"

// 通过该通道，获取java对象，调用java方法
class extension_sdk_demo_jni_2_api final {
public:
    static extension_sdk_demo_jni_2_api instance;
    static extension_sdk_demo_jni_2_api* getInstance() {
        return &instance;
    }
public:
 void adapterNativeInit(std::shared_ptr<ExtensionSdkDemoAdapterJNIListener2> listener1);

 void adapterNativeHello();

 void adapterNativeSendMessage(int number, std::string string);

 void adapterNativeSendMessageWithJson(int number, std::string json);

 void adapterNativeSendMessageWithPB(int number, std::string bytes);

    void adapterNativeHelloEcho();

    void adapterNativeSendMessageEcho(int number, std::string string);

    void adapterNativeSendMessageWithJsonEcho(int number, std::string json);

    void adapterNativeSendMessageWithPBEcho(int number, std::string bytes);

private:
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener2> _listener;
};

#endif //ANDROID_EXTENSION_SDK_DEMO_JNI_2_API_H
