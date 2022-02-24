//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_jni_2_api.h"

void extension_sdk_demo_jni_2_api::adapterNativeInit(std::shared_ptr<ExtensionSdkDemoAdapterJNIListener2> listener2) {
    // todo: jni部分 创建静态单实例java对象
    this->_listener = listener2;
}

void extension_sdk_demo_jni_2_api::adapterNativeHello() {
    // todo: jni部分
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessage(int number, std::string string) {
// todo: jni部分
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithJson(int number, std::string json) {
// todo: jni部分
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithPB(int number, std::string bytes) {
// todo: jni部分
}

void extension_sdk_demo_jni_2_api::adapterNativeHelloEcho() {
    this->_listener->adapterNativeHelloEcho();
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageEcho(int number, std::string string) {
    this->_listener->adapterNativeSendMessageEcho(number, string);
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithJsonEcho(int number, std::string json) {
    this->_listener->adapterNativeSendMessageWithJsonEcho(number, json);
}

void extension_sdk_demo_jni_2_api::adapterNativeSendMessageWithPBEcho(int number, std::string bytes) {
    this->_listener->adapterNativeSendMessageWithPBEcho(number, bytes);
}