//
// Created by asterisk on 2022/3/2.
//

#ifndef ANDROID_EXTENSIONSDKDEMOSDKAPI_H
#define ANDROID_EXTENSIONSDKDEMOSDKAPI_H

#include "ExtensionSdkDemoObject.h"
#include <memory>
#include <string>

E_SDK_NAMESPACE_BEGIN

/// 各个语言平台的分发接口
class ExtensionSdkDemoSdkApi {
public:
    virtual ~ExtensionSdkDemoSdkApi() {}

    virtual void setListener(std::shared_ptr<ExtensionSdkDemoObject> listener) = 0;

    virtual void
    sdkApi(const std::string &methodType,
           const std::shared_ptr<ExtensionSdkDemoObject> params,
           const std::shared_ptr<ExtensionSdkDemoObject> &callback) = 0;
};

ExtensionSdkDemoSdkApi *ExtensionSdkDemoSdkApi_getInstance();

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOSDKAPI_H
