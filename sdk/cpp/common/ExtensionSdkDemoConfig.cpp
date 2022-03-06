//
// Created by asterisk on 2022/3/1.
//

#include "ExtensionSdkDemoConfig.h"

E_SDK_NAMESPACE_BEGIN

ExtensionSdkDemoParamsTypeEValue ExtensionSdkDemoConfig::current_params_type = ExtensionSdkDemoParamsTypeEValue::PARAMS_JSON;
const std::string ExtensionSdkDemoConfig::current_ext_sdk_version = "1.0.0";

#if defined(JAVA_LANGUAGE)
const ExtensionSdkDemoLanguageTypeEValue ExtensionSdkDemoConfig::current_language_type = ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_JAVA;
#elif defined(CPP_LANGUAGE)
const ExtensionSdkDemoLanguageTypeEValue ExtensionSdkDemoConfig::current_language_type = ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_CPP;
#elif defined(OBJC_LANGUAGE)
const ExtensionSdkDemoLanguageTypeEValue ExtensionSdkDemoConfig::current_language_type = ExtensionSdkDemoLanguageTypeEValue::LANGUAGE_OBJECTIVE_C;
#else
#error "Please specify the language macro definition."
#endif

E_SDK_NAMESPACE_END