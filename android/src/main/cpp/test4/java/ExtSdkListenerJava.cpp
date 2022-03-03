//
// Created by asterisk on 2022/3/3.
//

#include "ExtSdkListenerJava.h"
#include "ExtSdkJniHelper.h"

EXT_SDK_NAMESPACE_BEGIN

ExtSdkMessageListenerJava::ExtSdkMessageListenerJava(jobject object):ExtSdkMessageListener() {
    JNIEnv *env = 0;
    env = ExtSdkJniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    obj = env->NewGlobalRef(object);
}

ExtSdkMessageListenerJava::~ExtSdkMessageListenerJava() {
    JNIEnv *env = 0;
    env = ExtSdkJniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;
    env->DeleteGlobalRef(obj);
}

void ExtSdkMessageListenerJava::onNewMessages(const ExtSdkObject &list) {
    // todo: 处理收到的消息
}

EXT_SDK_NAMESPACE_END