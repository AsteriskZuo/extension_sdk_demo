//
// Created by 佐玉 on 2022/2/25.
//

#ifndef ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H
#define ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H

#include <memory>
#include <string>
#include "extension_sdk_demo_jni_listener_1.h"

// 该C++封装层对上层可见，同时调用下层JNI部分，间接调用原生SDK
class extension_sdk_demo_cpp_wrapper {
public:
    static extension_sdk_demo_cpp_wrapper _instance;
    static extension_sdk_demo_cpp_wrapper* getInstance() {
        return &_instance;
    }
public:
    void cpp_wrapper_init(const std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> listener1);

    void cpp_wrapper_hello();

    void cpp_wrapper_send_message(int number, const char *string);

    void cpp_wrapper_send_message_with_json(int number, const char *json);

    void cpp_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size);
private:
    std::shared_ptr<ExtensionSdkDemoAdapterJNIListener1> _listener;
};



#endif //ANDROID_EXTENSION_SDK_DEMO_CPP_WRAPPER_H
