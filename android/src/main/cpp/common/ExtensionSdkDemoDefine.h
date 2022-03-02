//
// Created by asterisk on 2022/3/2.
//

// https://www.cnblogs.com/wnwin/p/9602047.html

#ifndef ANDROID_EXTENSIONSDKDEMODEFINE_H
#define ANDROID_EXTENSIONSDKDEMODEFINE_H

#if defined(JAVA_LANGUAGE)
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif

#if defined(FLUTTER_PLATFORM)
#elif defined(REACT_NATIVE_PLATFORM)
#elif defined(UNITY_PLATFORM)
#else
#error "Please specify the platform macro definition."
#endif

#define E_SDK_NAMESPACE_BEGIN namespace com { namespace example { namespace extension_sdk_demo {
#define E_SDK_NAMESPACE_END }}}
#define E_SDK_NAMESPACE_USING using namespace com::example::extension_sdk_demo;

#endif //ANDROID_EXTENSIONSDKDEMODEFINE_H
