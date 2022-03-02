//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_EXTENSIONSDKDEMOLISTENER_H
#define ANDROID_EXTENSIONSDKDEMOLISTENER_H

#include "ExtensionSdkDemoObject.h"

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoBaseListener {
public:
    virtual ~ExtensionSdkDemoBaseListener() {}
};

/// 更多的listener
class ExtensionSdkDemoMessageListener : public ExtensionSdkDemoBaseListener {
public:
    virtual ~ExtensionSdkDemoMessageListener() {}

public:
    virtual void onNewMessages(const ExtensionSdkDemoObject &list) = 0;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOLISTENER_H
