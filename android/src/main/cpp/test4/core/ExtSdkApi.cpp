//
// Created by asterisk on 2022/3/3.
//

#include "ExtSdkApi.h"
#include "wrapper/ExtSdkClient.h"
#include "ExtSdkMethodType.h"
#include "ExtSdkJniHelper.h"

#if defined(JAVA_LANGUAGE)
#include "ExtSdkObjectJava.h"
#include "ExtSdkListenerJava.h"
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif

EXT_SDK_NAMESPACE_BEGIN

ExtSdkApi ExtSdkApi::instance;

void ExtSdkApi::init(const std::shared_ptr<ExtSdkObject> config) {
#if defined(JAVA_LANGUAGE)
    std::shared_ptr<ExtSdkObjectJava> config_impl = std::dynamic_pointer_cast<ExtSdkObjectJava>(config);
    config_impl->obj;
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
}

void ExtSdkApi::addListener(const std::shared_ptr<ExtSdkObject> listener) {
    std::shared_ptr<ExtSdkMessageListener> listener_impl;// todo: 假设传过来的监听器是消息类型的，实际上需要经过一些方法判断什么类型的监听器对接下面sdk
#if defined(JAVA_LANGUAGE)
    std::shared_ptr<ExtSdkObjectJava> l = std::dynamic_pointer_cast<ExtSdkObjectJava>(listener);
    listener_impl = std::make_shared<ExtSdkMessageListenerJava>(l->obj);// todo: 需不需要全局？
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
    ExtSdkClient::getInstance()->addListener(listener_impl);
}

void ExtSdkApi::delListener(const std::shared_ptr<ExtSdkObject> listener) {

}

void
ExtSdkApi::callCoreApi(const std::string &methodType, const std::shared_ptr<ExtSdkObject> params,
                          const std::shared_ptr<ExtSdkObject> callback) {
    // todo: work_count: 1 -> 100+
    // todo: java object translate c++ object
    if (methodType == ExtSdkMethodType::METHOD_INIT) {

    } else if (methodType == ExtSdkMethodType::METHOD_ADD_LISTENER) {

    } else if (methodType == ExtSdkMethodType::METHOD_LOGIN) {
        std::string token;
#if defined(JAVA_LANGUAGE)
        std::shared_ptr<ExtSdkObjectJava> p = std::dynamic_pointer_cast<ExtSdkObjectJava>(params);
        p->obj;// todo: 从java对象里面解析出参数，复制给token
        // todo: 如果obj是一个复杂对象。例如：message
        JNIEnv *env = 0;
        env = ExtSdkJniHelper::getInstance()->attachCurrentThread();
        if (!env)
            return;
        jclass jcls = env->FindClass("java/util/HashMap");
        jmethodID jmid = env->GetMethodID(jcls, "get", "(Ljava/lang/Object;)Ljava/lang/Object;");
        jstring jstr = env->NewStringUTF("token");
        jobject jobj_result = env->CallObjectMethod(p->obj, jmid, jstr);
        env->DeleteLocalRef(jstr);
        const char* java_value = env->GetStringUTFChars((jstring)jobj_result, 0);
        token = java_value;
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
        ExtSdkClient::getInstance()->login(token, [callback](int code, const std::string&){
#if defined(JAVA_LANGUAGE)
            JNIEnv *env = 0;
            env = ExtSdkJniHelper::getInstance()->attachCurrentThread();
            if (!env)
                return;
            std::shared_ptr<ExtSdkObjectJava> c = std::dynamic_pointer_cast<ExtSdkObjectJava>(callback);
            c->obj;// todo: 利用java解析，调用对应回调方法 success or fail
            jclass jcls = env->FindClass("com/example/extension_sdk_demo/test4/common/ExtSdkCallback");
            jmethodID jmid_success = env->GetMethodID(jcls, "success", "(Ljava/lang/Object;)V");
            jmethodID jmid_fail = env->GetMethodID(jcls, "fail", "(ILjava/lang/Object;)V");

//            jclass jcls_integer = env->FindClass("java/lang/Integer");
//            jmethodID jmid_parseInt = env->GetStaticMethodID(jcls_integer, "parseInt", "(Ljava/lang/String;I)I");
//            jmethodID jmid_constructor = env->GetMethodID(jcls_integer, "<init>", "(I)V"); // todo: 为什么不让用，还抛出异常？
//            jobject jobj_integer = env->NewObject(jcls_integer, jmid_constructor, code);

            jclass jcls_map = env->FindClass("java/util/HashMap");
            jmethodID jmid_map_constructor = env->GetMethodID(jcls_map, "<init>", "()V");
            jmethodID jmid_put = env->GetMethodID(jcls_map, "put",
                                                  "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
            jobject jobj_map = env->NewObject(jcls_map, jmid_map_constructor);
            jstring jstr_key = env->NewStringUTF("code");
            jstring jstr_value = env->NewStringUTF(std::to_string(code).c_str());
            env->CallObjectMethod(jobj_map, jmid_put, jstr_key, jstr_value);
            env->DeleteLocalRef(jstr_key);
            env->DeleteLocalRef(jstr_value);

            env->CallVoidMethod(c->obj, jmid_success, jobj_map); // todo: 如果返回一个复杂对象，例如：message
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
        });
    } else if (methodType == ExtSdkMethodType::METHOD_LOGOUT) {

    } else {

    }
}

void ExtSdkApi::unInit() {

}

EXT_SDK_NAMESPACE_END