//
// Created by asterisk on 2022/3/2.
//

#ifndef ANDROID_EXTENSIONSDKDEMOOBJECTCPP_H
#define ANDROID_EXTENSIONSDKDEMOOBJECTCPP_H

#include "ExtensionSdkDemoObject.h"
#include <map>
#include <string>

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoObjectCpp : public ExtensionSdkDemoObject {
public:
    static std::map<std::string, std::string> params;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOOBJECTCPP_H
