//
// Created by asterisk on 2022/3/2.
//

#ifndef ANDROID_EXTENSIONSDKDEMOSDKAPIJAVA_H
#define ANDROID_EXTENSIONSDKDEMOSDKAPIJAVA_H

#include "ExtensionSdkDemoSdkApi.h"

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoSdkApiJava : public ExtensionSdkDemoSdkApi {
public:
    static void init();
    static void unInit();
    virtual void
    sdkApi(const std::string &methodType, const std::shared_ptr<ExtensionSdkDemoObject> params,
           const std::shared_ptr<ExtensionSdkDemoObject> &callback) override;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOSDKAPIJAVA_H
