//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKLISTENERJAVA_H
#define ANDROID_EXTSDKLISTENERJAVA_H

#include "ExtSdkListener.h"
#include <jni.h>

EXT_SDK_NAMESPACE_BEGIN

class ExtSdkMessageListenerJava final : public ExtSdkMessageListener {
public:
    ExtSdkMessageListenerJava(jobject object);
    ~ExtSdkMessageListenerJava();
    virtual void onNewMessages(const ExtSdkObject &list) override;

private:
    jobject obj;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKLISTENERJAVA_H
