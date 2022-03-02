//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_ExtensionSdkDemoParamsTypeEValue_H
#define ANDROID_ExtensionSdkDemoParamsTypeEValue_H

#include <string>
#include <map>
#include <stdexcept>
#include <cstdint>
#include "ExtensionSdkDemoDefine.h"

E_SDK_NAMESPACE_BEGIN

enum ExtensionSdkDemoParamsTypeEValue : std::uint16_t {
    PARAMS_JSON,
    PARAMS_Object,
    PARAMS_PB,
};

class ExtensionSdkDemoParamsTypeE {
public:
    static std::string getMethod(ExtensionSdkDemoParamsTypeEValue value) {
        auto iter = list.find(value);
        if (iter != list.end()) {
            return iter->second;
        }
        throw std::invalid_argument("This type is not support");
    }

    static ExtensionSdkDemoParamsTypeEValue getMethodValue(const std::string &method) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            if (i->second == method) {
                return i->first;
            }
        }
        throw std::invalid_argument("This type is not support");
    }
private:
    static const std::map<ExtensionSdkDemoParamsTypeEValue, std::string> list;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_ExtensionSdkDemoParamsTypeEValue_H
