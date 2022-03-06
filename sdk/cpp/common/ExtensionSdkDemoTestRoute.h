//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTENSIONSDKDEMOTESTROUTE_H
#define ANDROID_EXTENSIONSDKDEMOTESTROUTE_H

class ExtensionSdkDemoTestRoute {
public:
    static const int route;
};

/**
 * 测试路线
 * 1: dart -> java -> jni -> c++ -> jni -> java_sdk
 * 2: dart -> java -> jni -> c++ -> c++_wrapper -> jni -> java_sdk
 */
static const int ExtensionSdkDemoTestRoute::route = 1;

#endif //ANDROID_EXTENSIONSDKDEMOTESTROUTE_H
