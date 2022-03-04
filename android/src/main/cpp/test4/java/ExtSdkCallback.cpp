//
// Created by asterisk on 2022/3/4.
//

#include "ExtSdkCallback.h"
#include "ExtSdkMethodType.h"
#include <jni.h>
#include <string>
#include <functional>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkCallbackJniR_nativeSuccess(JNIEnv *env,
                                                                                 jobject thiz,
                                                                                 jlong obj,
                                                                                 jstring method_type,
                                                                                 jobject data) {
    // TODO: implement nativeSuccess()
    // todo: 根据方法，确定解析参数
    EXT_SDK_NAMESPACE_USING
    const char* cpp_method_type = env->GetStringUTFChars(method_type, 0);
    if (cpp_method_type == ExtSdkMethodType::METHOD_INIT) {

    } else if (cpp_method_type == ExtSdkMethodType::METHOD_ADD_LISTENER) {

    } else if (cpp_method_type == ExtSdkMethodType::METHOD_LOGIN) {
        std::function<void(int, std::string)>*p_function = (std::function<void(int, std::string)>*)obj;
        // todo: 解析参数
        (*p_function)(1, "ok");
        delete p_function;
    } else if (cpp_method_type == ExtSdkMethodType::METHOD_LOGOUT) {

    } else if (cpp_method_type == ExtSdkMethodType::METHOD_HELLO) {

    } else {

    }

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_extension_1sdk_1demo_test4_jni_ExtSdkCallbackJniR_nativeFail(JNIEnv *env,
                                                                              jobject thiz,
                                                                              jlong obj,
                                                                              jstring method_type,
                                                                              jint code,
                                                                              jobject ext) {
    // TODO: implement nativeFail()
    // todo: 和success一样，这个知识demo
}