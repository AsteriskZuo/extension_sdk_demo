//
// Created by asterisk on 2022/3/2.
//

#include <jni.h>
#include <string>
#include <iostream>
#include "jni_helper.h"
#include "ExtensionSdkDemoSdkApiJava.h"
#include "ExtensionSdkDemoObjectJava.h"

E_SDK_NAMESPACE_BEGIN

jclass jclsGSdkApi = 0;
jmethodID jclsGSdkApi_getInstance = 0;
jmethodID jclsGSdkApi_sdkApi = 0;

void ExtensionSdkDemoSdkApiJava::init() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    jclass jclsSdkApi = env->FindClass(
            "com/example/extension_sdk_demo/sdk/ExtensionSdkDemoSdkApi");
    if (env->ExceptionCheck() && 0 == jclsSdkApi) {
        env->Throw(env->ExceptionOccurred());
    }
    jclsGSdkApi = (jclass) env->NewGlobalRef(jclsSdkApi);
    env->DeleteLocalRef(jclsSdkApi);
    jclsSdkApi = 0;
    jclsGSdkApi_getInstance = env->GetStaticMethodID(jclsGSdkApi,
                                                     "getInstance",
                                                     "()Lcom/example/extension_sdk_demo/sdk/ExtensionSdkDemoSdkApi;");
    jclsGSdkApi_sdkApi = env->GetMethodID(jclsGSdkApi, "sdkApi",
                                          "(Ljava/lang/String;Ljava/lang/Object;Lcom/example/extension_sdk_demo/common/ExtensionSdkDemoCallback;)V");
}

void ExtensionSdkDemoSdkApiJava::unInit() {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    if (jclsGSdkApi)
        env->DeleteGlobalRef(jclsGSdkApi);
    jclsGSdkApi_getInstance = 0;
    jclsGSdkApi_sdkApi = 0;
}

void ExtensionSdkDemoSdkApiJava::sdkApi(const std::string &methodType,
                                        const std::shared_ptr<ExtensionSdkDemoObject> params,
                                        const std::shared_ptr<ExtensionSdkDemoObject> &callback) {
    // todo: 构造java对象，调用对应方法
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    std::shared_ptr<ExtensionSdkDemoObjectJava> cpp_params = std::dynamic_pointer_cast<ExtensionSdkDemoObjectJava>(params);
    std::shared_ptr<ExtensionSdkDemoObjectJava> cpp_callback = std::dynamic_pointer_cast<ExtensionSdkDemoObjectJava>(callback);
    jstring java_method_type = env->NewStringUTF(methodType.c_str());
    jobject sdkApi = env->CallStaticObjectMethod(jclsGSdkApi, jclsGSdkApi_getInstance);
    env->CallVoidMethod(sdkApi, jclsGSdkApi_sdkApi, java_method_type, cpp_params->obj, cpp_callback->obj);
    env->DeleteLocalRef(java_method_type);
}

E_SDK_NAMESPACE_END