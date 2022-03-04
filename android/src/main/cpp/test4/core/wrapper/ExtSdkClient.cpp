//
// Created by asterisk on 2022/3/3.
//


#include "ExtSdkMethodType.h"
#include "ExtSdkClient.h"

#if defined(JAVA_LANGUAGE)
#include "ExtSdkApiJni.h"
#include "ExtSdkJniHelper.h"
#include "ExtSdkObjectJava.h"
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif

EXT_SDK_NAMESPACE_BEGIN

ExtSdkClient ExtSdkClient::instance;

void ExtSdkClient::init(const std::shared_ptr<ExtSdkConfig> config) {

}
void ExtSdkClient::addListener(const std::shared_ptr<ExtSdkMessageListener> listener) {
    // todo: 模拟调用jni, oc等，方法、参数、回调
}
void ExtSdkClient::login(const std::string token, const std::function<void(int code, std::string)> result) {
    // todo: work_count: 1 -> 1, but 100+ apis
    // todo: c++ object translate to java object
#if defined(JAVA_LANGUAGE)
    // todo: 这里需要放在另外的地方，放在这里是方便演示
    jobject obj;// todo: 实际需要创建java的map对象

    JNIEnv *env = 0;
    env = ExtSdkJniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;

    jclass jcls_map = env->FindClass("java/util/HashMap");
    jmethodID jmid_map_constructor = env->GetMethodID(jcls_map, "<init>", "()V");
    jmethodID jmid_put = env->GetMethodID(jcls_map, "put",
                                          "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
    jobject jobj_map = env->NewObject(jcls_map, jmid_map_constructor);
    jstring jstr_key = env->NewStringUTF("token");
    jstring jstr_value = env->NewStringUTF(token.c_str());
    env->CallObjectMethod(jobj_map, jmid_put, jstr_key, jstr_value);
    env->DeleteLocalRef(jstr_key);
    env->DeleteLocalRef(jstr_value);
    obj = jobj_map;

    jobject obj2; // todo: 实际需要创建的回调对象， 该回调对象持有result，回来的时候调用result
    jclass jcls_cb = env->FindClass("com/example/extension_sdk_demo/test4/jni/ExtSdkCallbackJniR");
    jmethodID jmid_cb_constructor = env->GetMethodID(jcls_cb, "<init>", "()V");
    jmethodID jmid_cb_setNative = env->GetMethodID(jcls_cb, "setNativeObj", "(J)V");
    jmethodID jmid_cb_setMethodType = env->GetMethodID(jcls_cb, "setMethodType", "(Ljava/lang/String;)V");
    jstring jstr_method_type = env->NewStringUTF(ExtSdkMethodType::METHOD_LOGIN);

    std::function<void(int, std::string)>* p_result = new std::function<void(int, std::string)>(result);
    jobject jobj_cb = env->NewObject(jcls_cb, jmid_cb_constructor);
    env->CallVoidMethod(jobj_cb, jmid_cb_setNative, (jlong)p_result);
    env->CallVoidMethod(jobj_cb, jmid_cb_setMethodType, jstr_method_type);
    env->DeleteLocalRef(jstr_method_type);
    obj2 = jobj_cb;

    std::shared_ptr<ExtSdkObjectJava> java_params = std::make_shared<ExtSdkObjectJava>(obj);
    std::shared_ptr<ExtSdkObjectJava> java_callback = std::make_shared<ExtSdkObjectJava>(obj2);
    ExtSdkApiJni::getInstance()->callSdkApi(ExtSdkMethodType::METHOD_LOGIN, java_params, java_callback);
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
}
void ExtSdkClient::logout() {

}

EXT_SDK_NAMESPACE_END