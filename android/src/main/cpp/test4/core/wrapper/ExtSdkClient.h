//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKCLIENT_H
#define ANDROID_EXTSDKCLIENT_H


#include <string>
#include <memory>
#include <functional>
#include <ExtSdkConfig.h>
#include "ExtSdkListener.h"

EXT_SDK_NAMESPACE_BEGIN

class ExtSdkClient {
public:
    static ExtSdkClient *getInstance() {
        return &instance;
    }

    void init(const std::shared_ptr<ExtSdkConfig> config);
    void addListener(const std::shared_ptr<ExtSdkMessageListener> listener);
    void login(const std::string token, const std::function<void(int code, std::string)> result);
    void logout();

private:
    static ExtSdkClient instance;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKCLIENT_H
