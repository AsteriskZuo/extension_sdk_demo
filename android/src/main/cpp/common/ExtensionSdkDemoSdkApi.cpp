//
// Created by asterisk on 2022/3/2.
//

#include "ExtensionSdkDemoSdkApi.h"

#if defined(JAVA_LANGUAGE)

#include "ExtensionSdkDemoSdkApiJava.h"

#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif

E_SDK_NAMESPACE_BEGIN

ExtensionSdkDemoSdkApi *ExtensionSdkDemoSdkApi_getInstance() {
#if defined(JAVA_LANGUAGE)
    static ExtensionSdkDemoSdkApiJava instance;
    return &instance;
#elif defined(CPP_LANGUAGE)
#elif defined(OBJC_LANGUAGE)
#else
#error "Please specify the language macro definition."
#endif
}

E_SDK_NAMESPACE_END