//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_EXTENSIONSDKDEMOCONFIG_H
#define ANDROID_EXTENSIONSDKDEMOCONFIG_H

#include <string>
#include "ExtensionSdkDemoDefine.h"
#include "ExtensionSdkDemoParamsTypeE.h"
#include "ExtensionSdkDemoLanguageTypeE.h"

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoConfig {
public:
    static ExtensionSdkDemoParamsTypeEValue current_params_type;
    static const ExtensionSdkDemoLanguageTypeEValue current_language_type;
    static const std::string current_ext_sdk_version;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOCONFIG_H
