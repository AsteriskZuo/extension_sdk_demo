//
// Created by 佐玉 on 2022/2/24.
//

#ifndef ANDROID_EXTENSION_SDK_DEMO_JNI_LISTENER_1_H
#define ANDROID_EXTENSION_SDK_DEMO_JNI_LISTENER_1_H

#include <jni.h>
#include <string>

class ExtensionSdkDemoAdapterJNIListener1 {
public:
    ExtensionSdkDemoAdapterJNIListener1(jobject listener);
    virtual ~ExtensionSdkDemoAdapterJNIListener1();

    static void init();
    static void uninit();

    void adapterNativeHelloEcho();

    void adapterNativeSendMessageEcho(int number, std::string string);

    void adapterNativeSendMessageWithJsonEcho(int number, std::string json);

    void adapterNativeSendMessageWithPBEcho(int number, char* bytes, int bytes_size);

private:
    jobject _listener;
};

#endif //ANDROID_EXTENSION_SDK_DEMO_JNI_LISTENER_1_H
