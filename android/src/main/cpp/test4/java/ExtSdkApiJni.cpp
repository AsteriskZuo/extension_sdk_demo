//
// Created by asterisk on 2022/3/3.
//

#include "ExtSdkApiJni.h"
#include "ExtSdkObjectJava.h"
#include "ExtSdkListenerJava.h"
#include "ExtSdkApi.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkApiJni_init(JNIEnv *env, jclass clazz,
                                                                  jobject configures) {
    // TODO: implement init()
    EXT_SDK_NAMESPACE_USING
    std::shared_ptr<ExtSdkObject> java_config = std::make_shared<ExtSdkObjectJava>(configures);
    ExtSdkApi::getInstance()->init(java_config);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkApiJni_addListener(JNIEnv *env, jclass clazz,
                                                                         jobject listener) {
    // TODO: implement addListener()
    EXT_SDK_NAMESPACE_USING
    std::shared_ptr<ExtSdkObject> java_listener = std::make_shared<ExtSdkObjectJava>(listener);
    ExtSdkApi::getInstance()->addListener(java_listener);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkApiJni_delListener(JNIEnv *env, jclass clazz,
                                                                         jobject listener) {
    // TODO: implement delListener()
    EXT_SDK_NAMESPACE_USING
    std::shared_ptr<ExtSdkObject> java_listener = std::make_shared<ExtSdkObjectJava>(listener);
    ExtSdkApi::getInstance()->delListener(java_listener);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkApiJni_callJniApi(JNIEnv *env, jclass clazz,
                                                                        jstring method_type,
                                                                        jobject params,
                                                                        jobject callback) {
    // TODO: implement callJniApi()
    EXT_SDK_NAMESPACE_USING
    std::shared_ptr<ExtSdkObject> java_params = std::make_shared<ExtSdkObjectJava>(params);
    std::shared_ptr<ExtSdkObject> java_callback = std::make_shared<ExtSdkObjectJava>(callback);
    const char* java_method_type = env->GetStringUTFChars(method_type, 0);
    ExtSdkApi::getInstance()->callCoreApi(java_method_type, java_params, java_callback);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkApiJni_unInit(JNIEnv *env, jclass clazz) {
    // TODO: implement unInit()
    EXT_SDK_NAMESPACE_USING
    ExtSdkApi::getInstance()->unInit();
}

EXT_SDK_NAMESPACE_BEGIN

ExtSdkApiJni ExtSdkApiJni::instance;

void ExtSdkApiJni::init(const std::shared_ptr<ExtSdkObject> config) {

}

void ExtSdkApiJni::addListener(const std::shared_ptr<ExtSdkObject> listener) {

}

void ExtSdkApiJni::delListener(const std::shared_ptr<ExtSdkObject> listener) {

}

void
ExtSdkApiJni::callSdkApi(const std::string &methodType, const std::shared_ptr<ExtSdkObject> params,
                         const std::shared_ptr<ExtSdkObject> callback) {
    // todo: 准备调用原生sdk，之后还需要在做一次分发
    // todo: 利用反射创建java对象`ExtSdkApiJniR`，java对象接收调用之后，进行分发，调用原生SDK

}

void ExtSdkApiJni::unInit() {

}

EXT_SDK_NAMESPACE_END