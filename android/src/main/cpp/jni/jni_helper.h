//
// Created by 佐玉 on 2022/2/24.
//

#ifndef JNI_HELPER_H
#define JNI_HELPER_H

#include <jni.h>
#include <android/log.h>

class JniHelper {

public:
    static JniHelper* getInstance();
    void init(JavaVM* vm);
    void uninit(JavaVM* vm);
    JNIEnv *attachCurrentThread();
    void detachCurrentThread();

private:
    static void _destructor(void*);
};

// Android log function wrappers
static const char* kTAG = "JNIHELPER";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define LOGW(...) \
  ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define LOGE(...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))


#endif //JNI_HELPER_H
