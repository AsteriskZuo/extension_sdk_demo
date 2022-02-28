//
// Created by 佐玉 on 2022/2/25.
//

#ifndef ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H
#define ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H

#include <memory>
#include <string>
#include "extension_sdk_demo_jni_listener_1.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*hello_callback)();

typedef void (*send_message_callback)(int, const char *);

typedef void (*send_message_with_json_callback)(int, const char *);

typedef void (*send_message_with_pb_callback)(int, const char *, int);

void c_wrapper_init(
        hello_callback helloCallback,
        send_message_callback sendMessageCallback,
        send_message_with_json_callback sendMessageWithJsonCallback,
        send_message_with_pb_callback sendMessageWithPbCallback
);

void c_wrapper_hello();

void c_wrapper_send_message(int number, const char *string);

void c_wrapper_send_message_with_json(int number, const char *json);

void c_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size);

#ifdef __cplusplus
}
#endif

// 该C++封装层对上层可见，同时调用下层JNI部分，间接调用原生SDK
class extension_sdk_demo_cpp_wrapper {
public:
    static extension_sdk_demo_cpp_wrapper _instance;
    static extension_sdk_demo_cpp_wrapper* getInstance() {
        return &_instance;
    }
public:
    void cpp_wrapper_init( std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener1);

    void cpp_wrapper_hello();

    void cpp_wrapper_send_message(int number, const char *string);

    void cpp_wrapper_send_message_with_json(int number, const char *json);

    void cpp_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size);
private:
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> _listener;
};



#endif //ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H
