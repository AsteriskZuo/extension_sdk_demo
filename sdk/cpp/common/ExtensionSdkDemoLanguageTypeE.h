//
// Created by asterisk on 2022/3/2.
//

#ifndef ANDROID_EXTENSIONSDKDEMOLANGUAGETYPEE_H
#define ANDROID_EXTENSIONSDKDEMOLANGUAGETYPEE_H

#include <string>
#include <map>
#include <stdexcept>
#include <cstdint>
#include "ExtensionSdkDemoDefine.h"

E_SDK_NAMESPACE_BEGIN

enum class ExtensionSdkDemoLanguageTypeEValue : std::uint8_t {
    LANGUAGE_CPP, // with C language
    LANGUAGE_JAVA, // with kotlin language
    LANGUAGE_OBJECTIVE_C, // with C language, swift language
};

class ExtensionSdkDemoLanguageTypeE {
    static const std::map<ExtensionSdkDemoLanguageTypeEValue, std::string> list;
public:
    static std::string getMethod(ExtensionSdkDemoLanguageTypeEValue value) {
        auto iter = list.find(value);
        if (iter != list.end()) {
            return iter->second;
        }
        throw std::invalid_argument("This type is not support");
    }

    static ExtensionSdkDemoLanguageTypeEValue getMethodValue(const std::string &language) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            if (i->second == language) {
                return i->first;
            }
        }
        throw std::invalid_argument("This type is not support");
    }
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOLANGUAGETYPEE_H
