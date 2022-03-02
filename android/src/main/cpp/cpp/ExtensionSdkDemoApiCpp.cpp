//
// Created by asterisk on 2022/3/2.
//

#include "ExtensionSdkDemoApiCpp.h"
#include "ExtensionSdkDemoObjectCpp.h"
#include "ExtensionSdkDemoSdkApi.h"
#include <iostream>

E_SDK_NAMESPACE_BEGIN

ExtensionSdkDemoApiCpp ExtensionSdkDemoApiCpp::_instance;

void ExtensionSdkDemoApiCpp::init(const std::shared_ptr<ExtensionSdkDemoObject> configures) {
    std::shared_ptr<ExtensionSdkDemoObjectCpp> c = std::dynamic_pointer_cast<ExtensionSdkDemoObjectCpp>(
            configures);
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    // todo: 根据参数设置配置信息
}

void ExtensionSdkDemoApiCpp::callSdkApi(const std::string &methodType,
                                        const std::shared_ptr<ExtensionSdkDemoObject> params,
                                        const std::shared_ptr<ExtensionSdkDemoObject> &callback) {
    std::cout << __FUNCTION__ << ":" << __LINE__ << std::endl;
    // todo: 根据不同的语言调用不同的sdk的封装对象
    ExtensionSdkDemoSdkApi_getInstance()->sdkApi(methodType, params, callback);
}

E_SDK_NAMESPACE_END