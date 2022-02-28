//
// Created by 佐玉 on 2022/2/24.
//

#include "jni_helper.h"
#include "extension_sdk_demo_jni_listener_1.h"
#include "extension_sdk_demo_jni_2_api.h"
#include <pthread.h>

JavaVM* gvm = NULL;
static pthread_key_t gkey = 0;

JniHelper* JniHelper::getInstance()
{
    static JniHelper ghelper;
    return &ghelper;
}

void JniHelper::init(JavaVM* vm)
{
    gvm = vm;
    ExtensionSdkDemoAdapterJNIListener1::init();
    extension_sdk_demo_jni_2_api::init();
}
void JniHelper::uninit(JavaVM* vm) {
    ExtensionSdkDemoAdapterJNIListener1::uninit();
    extension_sdk_demo_jni_2_api::uninit();
}
JNIEnv *JniHelper::attachCurrentThread()
{
    JNIEnv* env = 0;
    if (!gvm)
        return env;
    if (gvm->GetEnv((void**)&env, JNI_VERSION_1_6) == JNI_OK)
        return env;
    if (0 > gvm->AttachCurrentThread(&env, NULL)) {
        LOGW("env attach current thread is failed.");
        return env;
    }
    pthread_key_create(&gkey, JniHelper::_destructor);
    if (pthread_getspecific(gkey) == NULL) {
        pthread_setspecific(gkey, env);
    }
    return env;
}
void JniHelper::detachCurrentThread()
{
    if (gvm)
        gvm->DetachCurrentThread();
}
void JniHelper::_destructor(void* p)
{
    JniHelper::getInstance()->detachCurrentThread();
}

/*
* processing one time initialization:
*     Cache the javaVM into our context
*     Find class ID for JniHelper
*     Create an instance of JniHelper
*     Make global reference since we are using them from a native thread
* Note:
*     All resources allocated here are never released by application
*     we rely on system to free all global refs when it goes away;
*     the pairing function JNI_OnUnload() never gets called at all.
*/
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

    JNIEnv *env = 0;
    if (vm && vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR; // JNI version not supported.
    }

    JniHelper::getInstance()->init(vm);

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv *env = 0;
    env = JniHelper::getInstance()->attachCurrentThread();
    if (!env)
        return;

    JniHelper::getInstance()->uninit(vm);
}