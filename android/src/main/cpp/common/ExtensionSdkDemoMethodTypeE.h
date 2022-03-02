//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_EXTENSIONSDKDEMOMETHODTYPEE_H
#define ANDROID_EXTENSIONSDKDEMOMETHODTYPEE_H

#include <string>
#include <map>
#include "ExtensionSdkDemoDefine.h"

E_SDK_NAMESPACE_BEGIN

enum class ExtensionSdkDemoMethodTypeEValue : std::uint16_t {
    METHOD_HELLO,
    METHOD_INIT,
    METHOD_LOGIN,
    METHOD_LOGOUT,
};

class ExtensionSdkDemoMethodTypeE {
    static std::map<ExtensionSdkDemoMethodTypeEValue, std::string> list;
public:
    static std::string getMethod(ExtensionSdkDemoMethodTypeEValue value) {
        auto iter = list.find(value);
        if (iter != list.end()) {
            return iter->second;
        }
        return "";
    }

    static ExtensionSdkDemoMethodTypeEValue getMethodValue(const std::string &method) {
        return ExtensionSdkDemoMethodTypeEValue::METHOD_HELLO;
    }
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOMETHODTYPEE_H
