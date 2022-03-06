//
// Created by 佐玉 on 2022/2/25.
//

#include "extension_sdk_demo_c_wrapper.h"
//#include "extension_sdk_demo_cpp_wrapper.h"
//
//#ifdef __cplusplus
//#include <string>
//#include <memory>
//#include <iostream>
//#endif
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//void c_wrapper_init(
//        hello_callback helloCallback,
//        send_message_callback sendMessageCallback,
//        send_message_with_json_callback sendMessageWithJsonCallback,
//        send_message_with_pb_callback sendMessageWithPbCallback
//) {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
//    // todo:
//    // std::shard_ptr<ExtensionSdkDemoAdapterJNIListener1> listener = std::make_shared<ExtensionSdkDemoAdapterJNIListener>();
//    // extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_init();
//}
//
//void c_wrapper_hello() {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
//    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_hello();
//}
//
//void c_wrapper_send_message(int number, const char *string) {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
//    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message(number, string);
//}
//
//void c_wrapper_send_message_with_json(int number, const char *json) {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
//    extension_sdk_demo_cpp_wrapper::getInstance()->cpp_wrapper_send_message_with_json(number, json);
//}
//
//void c_wrapper_send_message_with_pb(int number, const char *bytes, int bytes_size) {
//    std::cout << __FUNCTION__ << ":" << __LINE__  << std::endl;
//    extension_sdk_demo_cpp_wrapper::getInstance()->c_wrapper_send_message_with_pb(number, bytes, bytes_size);
//}
//
//#ifdef __cplusplus
//}
//#endif