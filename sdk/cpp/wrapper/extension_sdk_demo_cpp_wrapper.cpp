//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_cpp_wrapper.h"
#include "extension_sdk_demo_jni_2_listener.h"
#include "extension_sdk_demo_jni_2_api.h"

#include <memory>
#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

void c_wrapper_init(
        hello_callback helloCallback,
        send_message_callback sendMessageCallback,
        send_message_with_json_callback sendMessageWithJsonCallback,
        send_message_with_pb_callback sendMessageWithPbCallback
) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    // todo:
    // std::shard_ptr<ExtensionSdkDemoAdapterJNIListener1> listener = std::make_shared<ExtensionSdkDemoAdapterJNIListener>();
    // extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_init();
}

void c_wrapper_hello() {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_hello();
}

void c_wrapper_send_message(int number, const char *string) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message(number, string);
}

void c_wrapper_send_message_with_json(int number, const char *json) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message_with_json(number, json);
}

void c_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message_with_pb(number, bytes, bytes_size);
}

#ifdef __cplusplus
}
#endif

class ExtensionSdkDemoAdapterJNIListener2Impl : public ExtensionSdkDemoAdapterJNIListener2 {
public:
    ExtensionSdkDemoAdapterJNIListener2Impl(std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener): _listener(listener) {
        std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    }
    virtual ~ExtensionSdkDemoAdapterJNIListener2Impl() {}
    void adapterNativeHelloEcho() override {
        std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
        _listener->adapterNativeHelloEcho();
    }


    void adapterNativeSendMessageEcho(int number, std::string string) override {
        std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
        _listener->adapterNativeSendMessageEcho(number, string);
    }

    void adapterNativeSendMessageWithJsonEcho(int number, std::string json) override {
        std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
        _listener->adapterNativeSendMessageWithJsonEcho(number, json);
    }

    void adapterNativeSendMessageWithPBEcho(int number, char* bytes, int bytes_size) override {
        std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
        _listener->adapterNativeSendMessageWithPBEcho(number, bytes, bytes_size);
    }

private:
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> _listener;
};

extension_sdk_demo_cpp_wrapper extension_sdk_demo_cpp_wrapper::_instance;

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_init( std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener1) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener2> s = std::make_shared<ExtensionSdkDemoAdapterJNIListener2Impl>(listener1);
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeInit(s);
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_hello() {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeHello();
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message(int number, const char *string) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessage(number, string);
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message_with_json(int number, const char *json) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithJson(number, json);
}

void extension_sdk_demo_cpp_wrapper::cpp_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size) {
    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
    extension_sdk_demo_jni_2_api::getInstance()->adapterNativeSendMessageWithPB(number, std::string(bytes, bytes_size));
}

