//
// Created by asterisk on 2022/3/3.
//

#ifndef ANDROID_EXTSDKMETHODTYPE_H
#define ANDROID_EXTSDKMETHODTYPE_H

#include <string>
#include "ExtSdkDefine.h"

EXT_SDK_NAMESPACE_BEGIN

class ExtSdkMethodType {
public:
    static const char* const METHOD_HELLO;
    static const char* const METHOD_INIT;
    static const char* const METHOD_ADD_LISTENER;
    static const char* const METHOD_LOGIN;
    static const char* const METHOD_LOGOUT;
};

EXT_SDK_NAMESPACE_END

#endif //ANDROID_EXTSDKMETHODTYPE_H
