//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKAPI_H
#define ANDROID_EXTSDKAPI_H

#include <ExtSdkObject.h>
#include <memory>
#include <string>

EXT_SDK_NAMESPACE_BEGIN

/// 分发接口
class ExtSdkApi {
public:
    static ExtSdkApi* getInstance() {
        return &instance;
    }

    void init(const std::shared_ptr<ExtSdkObject> config);
    void addListener(const std::shared_ptr<ExtSdkObject> listener);
    void delListener(const std::shared_ptr<ExtSdkObject> listener);
    void callCoreApi(const std::string& methodType, const std::shared_ptr<ExtSdkObject> params, const std::shared_ptr<ExtSdkObject> callback);
    void unInit();

private:
    static ExtSdkApi instance;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKAPI_H
