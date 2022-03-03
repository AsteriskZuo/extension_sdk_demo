//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_EXTENSIONSDKDEMOAPIJAVA_H
#define ANDROID_EXTENSIONSDKDEMOAPIJAVA_H

#include "ExtensionSdkDemoObjectJava.h"
#include <memory>
#include <jni.h>

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoApiJava {
    static ExtensionSdkDemoApiJava _instance;
public:
    static ExtensionSdkDemoApiJava *getInstance() {
        return &_instance;
    }

    void javaApi(const char *methodType, const std::shared_ptr<ExtensionSdkDemoObjectJava> params,
                 const std::shared_ptr<ExtensionSdkDemoObjectJava> &callback);
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOAPIJAVA_H
