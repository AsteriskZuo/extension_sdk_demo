//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_cpp_wrapper.h"
#include "extension_sdk_demo_jni_2_listener.h"
#include "extension_sdk_demo_jni_2_api.h"

class ExtensionSdkDemoAdapterJNIListener2Impl : public ExtensionSdkDemoAdapterJNIListener2 {
public:
    virtual ~ExtensionSdkDemoAdapterJNIListener2Impl(std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener): _listener(listener) {}
    void adapterNativeHelloEcho() override {
        _listener->adapterNativeHelloEcho();
    }


    void adapterNativeSendMessageEcho(int number, std::string string) override {
        _listener->adapterNativeSendMessageEcho(number, string);
    }

    void adapterNativeSendMessageWithJsonEcho(int number, std::string json) override {
        _listener->adapterNativeSendMessageWithJsonEcho(number, json);
    }

    void adapterNativeSendMessageWithPBEcho(int number, char* bytes, int bytes_size) override {
        _listener->adapterNativeSendMessageWithPBEcho(number, bytes, bytes_size);
    }

private:
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> _listener;
};

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_init(const std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener1) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeInit(std::make_shared<ExtensionSdkDemoAdapterJNIListener2Impl>());
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_hello() {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHello();
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message(int number, const char *string) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessage(number, string);
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message_with_json(int number, const char *json) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithJson(number, json);
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size) {
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithPB(number, std::string(bytes, bytes_size));
}

