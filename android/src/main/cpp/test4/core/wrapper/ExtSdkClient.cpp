//
// Created by asterisk on 2022/3/3.
//

#include "ExtSdkObjectJava.h"
#include "ExtSdkMethodType.h"
#include "ExtSdkClient.h"

#if defined(JAVA_LANGUAGE)
#include "ExtSdkApiJni.h"
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
    jobject obj2; // todo: 实际需要创建的回调对象， 该回调对象持有result，回来的时候调用result
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