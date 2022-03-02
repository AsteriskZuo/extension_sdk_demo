//
// Created by asterisk on 2022/3/1.
//

#include "ExtensionSdkDemoApiJava.h"
#include "ExtensionSdkDemoObjectJava.h"
#include "ExtensionSdkDemoApiCpp.h"
#include "ExtensionSdkDemoObjectCpp.h"
#include <jni.h>
#include <iostream>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_jni_ExtensionSdkDemoApiJni_init(JNIEnv *env, jclass clazz,
                                                                      jobject configures) {
    // TODO: implement init()
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    E_SDK_NAMESPACE_USING
    std::shared_ptr<ExtensionSdkDemoObjectCpp> cpp_params = std::make_shared<ExtensionSdkDemoObjectCpp>();
    // todo: 解析参数类型、语言类型等
    ExtensionSdkDemoApiCpp::getInstance()->init(cpp_params);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_jni_ExtensionSdkDemoApiJni_callJniApi(JNIEnv *env,
                                                                            jclass clazz,
                                                                            jstring method_type,
                                                                            jobject params,
                                                                            jobject callback) {
    // TODO: implement callJniApi()
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    E_SDK_NAMESPACE_USING
    std::shared_ptr<ExtensionSdkDemoObjectJava> cpp_params = std::make_shared<ExtensionSdkDemoObjectJava>();
    cpp_params->obj = params;
    std::shared_ptr<ExtensionSdkDemoObjectJava> cpp_callback = std::make_shared<ExtensionSdkDemoObjectJava>();
    cpp_callback->obj = callback;
    const char *c_method_type = env->GetStringUTFChars(method_type, 0);
    ExtensionSdkDemoApiJava::getInstance()->javaApi(c_method_type, cpp_params, cpp_callback);
}

E_SDK_NAMESPACE_BEGIN

ExtensionSdkDemoApiJava
        ExtensionSdkDemoApiJava::_instance;

void ExtensionSdkDemoApiJava::javaApi(const char *methodType,
                                      const std::shared_ptr<ExtensionSdkDemoObjectJava> params,
                                      const std::shared_ptr<ExtensionSdkDemoObjectJava> &callback) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    ExtensionSdkDemoApiCpp::getInstance()->callSdkApi(methodType, params, callback);
}

E_SDK_NAMESPACE_END