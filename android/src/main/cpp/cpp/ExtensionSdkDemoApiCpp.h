//
// Created by asterisk on 2022/3/2.
//

#ifndef ANDROID_EXTENSIONSDKDEMOAPICPP_H
#define ANDROID_EXTENSIONSDKDEMOAPICPP_H

#include <string>
#include "ExtensionSdkDemoObject.h"

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoApiCpp {
    static ExtensionSdkDemoApiCpp _instance;
public:
    static ExtensionSdkDemoApiCpp *getInstance() {
        return &_instance;
    }

    void init(const std::shared_ptr<ExtensionSdkDemoObject> configures);

    void setListener(const std::shared_ptr<ExtensionSdkDemoObject> listener);

    void
    callSdkApi(const std::string &methodType, const std::shared_ptr<ExtensionSdkDemoObject> params,
               const std::shared_ptr<ExtensionSdkDemoObject> &callback);
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOAPICPP_H
