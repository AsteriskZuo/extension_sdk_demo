//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKLISTENER_H
#define ANDROID_EXTSDKLISTENER_H

#include "ExtSdkDefine.h"
#include "ExtSdkObject.h"

EXT_SDK_NAMESPACE_BEGIN

class ExtSdkListener {
public:
    virtual ~ExtSdkListener() {}
};

/// 根据实际SDK的参数进行修改和添加
class ExtSdkMessageListener : public ExtSdkListener {
public:
    virtual ~ExtSdkMessageListener() {}
    virtual void onNewMessages(const ExtSdkObject &list) = 0;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKLISTENER_H
