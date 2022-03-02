//
// Created by asterisk on 2022/3/1.
//

#ifndef ANDROID_EXTENSIONSDKDEMOOBJECTJAVA_H
#define ANDROID_EXTENSIONSDKDEMOOBJECTJAVA_H

#include <jni.h>
#include "ExtensionSdkDemoObject.h"

E_SDK_NAMESPACE_BEGIN

class ExtensionSdkDemoObjectJava : public ExtensionSdkDemoObject {
public:
    jobject obj;
};

E_SDK_NAMESPACE_END

#endif //ANDROID_EXTENSIONSDKDEMOOBJECTJAVA_H
