package com.example.extension_sdk_demo.test4.jni;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.test4.common.ExtSdkBaseListener;
import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;
import com.example.extension_sdk_demo.test4.common.ExtSdkMethodType;
import com.example.extension_sdk_demo.test4.flutter.ExtSdkApiFlutter;

/// 承接C++反射调用
public class ExtSdkApiJniR {
    private static class SingleHolder {
        static ExtSdkApiJniR instance = new ExtSdkApiJniR();
    }

    public static ExtSdkApiJniR getInstance() {
        return ExtSdkApiJniR.SingleHolder.instance;
    }

    public void init(@NonNull Object configures) {

    }
    public void addListener(ExtSdkBaseListener listener) {

    }
    public void delListener(ExtSdkBaseListener listener) {

    }
    public void callSdkApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtSdkCallbackJniR callback) {
        // todo: work_count: 1 -> 100+
        // todo: java map params translate to java object
        // TODO: 由此进行分发调用原生sdk
        if (methodType.equals(ExtSdkMethodType.METHOD_INIT)) {

        } else if (methodType.equals(ExtSdkMethodType.METHOD_ADD_LISTENER)) {

        } else if (methodType.equals(ExtSdkMethodType.METHOD_LOGIN)) {
            // todo: 模拟回调情况
            if (true) {
                callback.success("ok");
            } else {
                callback.fail(1, "error");
            }
        } else if (methodType.equals(ExtSdkMethodType.METHOD_LOGOUT)) {

        } else if (methodType.equals(ExtSdkMethodType.METHOD_HELLO)) {

        } else {

        }
    }
    public void unInit() {

    }
}
