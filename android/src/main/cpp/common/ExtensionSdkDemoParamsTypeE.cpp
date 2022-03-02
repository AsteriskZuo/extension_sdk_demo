//
// Created by asterisk on 2022/3/1.
//

#include "ExtensionSdkDemoParamsTypeE.h"

E_SDK_NAMESPACE_BEGIN

const std::map<ExtensionSdkDemoParamsTypeEValue, std::string>
list = {
        {ExtensionSdkDemoParamsTypeEValue::PARAMS_JSON,   "json"},
        {ExtensionSdkDemoParamsTypeEValue::PARAMS_Object, "object"},
        {ExtensionSdkDemoParamsTypeEValue::PARAMS_PB,     "proto"},
};

E_SDK_NAMESPACE_END