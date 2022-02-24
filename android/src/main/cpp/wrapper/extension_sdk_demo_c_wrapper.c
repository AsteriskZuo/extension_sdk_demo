//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_c_wrapper.h"
#include "extension_sdk_demo_cpp_wrapper.h"

#ifdef __cplusplus
#include <string>
#include <memory>
#endif


void c_wrapper_init(
        hello_callback helloCallback,
        send_message_callback sendMessageCallback,
        send_message_with_json_callback sendMessageWithJsonCallback,
        send_message_with_pb_callback sendMessageWithPbCallback
) {
    // todo:
    // std::shard_ptr<ExtensionSdkDemoAdapterJNIListener1> listener = std::make_shared<ExtensionSdkDemoAdapterJNIListener>();
    // extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_init();
}

void c_wrapper_hello() {
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_hello();
}

void c_wrapper_send_message(int number, const char *string) {
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message(number, string);
}

void c_wrapper_send_message_with_json(int number, const char *json) {
    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message_with_json(number, json);
}

void c_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size) {
    extension_sdk_demo_cpp_wrapper::getInstance()->c_wrapper_send_message_with_pb(number, bytes, bytes_size);
}