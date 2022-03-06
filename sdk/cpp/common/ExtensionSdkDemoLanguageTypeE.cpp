//
// Created by asterisk on 2022/3/2.
//

#include "ExtensionSdkDemoLanguageTypeE.h"

E_SDK_NAMESPACE_BEGIN

const std::map<ExtensionSdkDemoLanguageTypeEValue, std::string>
ExtensionSdkDemoLanguageTypeE::list = {
        {ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_CPP,         "cpp"},
        {ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_JAVA,        "java"},
        {ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_OBJECTIVE_C, "objc"},
};

E_SDK_NAMESPACE_END