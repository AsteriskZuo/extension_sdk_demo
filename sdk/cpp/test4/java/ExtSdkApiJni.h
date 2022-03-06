//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKAPIJNI_H
#define ANDROID_EXTSDKAPIJNI_H

#include <ExtSdkObject.h>
#include <memory>
#include <string>

EXT_SDK_NAMESPACE_BEGIN

/// 分发接口
class ExtSdkApiJni {
public:
    static ExtSdkApiJni* getInstance() {
        return &instance;
    }

    void init(const std::shared_ptr<ExtSdkObject> config);
    void addListener(const std::shared_ptr<ExtSdkObject> listener);
    void delListener(const std::shared_ptr<ExtSdkObject> listener);
    void callSdkApi(const std::string& methodType, const std::shared_ptr<ExtSdkObject> params, const std::shared_ptr<ExtSdkObject> callback);
    void unInit();

private:
    static ExtSdkApiJni instance;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKAPIJNI_H
