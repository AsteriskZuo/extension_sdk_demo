package com.example.extension_sdk_demo.test4.flutter;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.ExtensionSdkDemoAdapter1;
import com.example.extension_sdk_demo.test4.common.ExtSdkApi;
import com.example.extension_sdk_demo.test4.common.ExtSdkBaseListener;
import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;
import com.example.extension_sdk_demo.test4.jni.ExtSdkApiJni;

import java.util.HashMap;

public class ExtSdkApiFlutter implements ExtSdkApi {

    private static class SingleHolder {
        static ExtSdkApiFlutter instance = new ExtSdkApiFlutter();
    }

    public static ExtSdkApiFlutter getInstance() {
        return ExtSdkApiFlutter.SingleHolder.instance;
    }

    @Override
    public void init(@NonNull Object config) {
        ExtSdkApiJni.init(config);
    }

    @Override
    public void unInit(@Nullable Object params) {
        ExtSdkApiJni.unInit();
    }

    @Override
    public void addListener(@NonNull ExtSdkBaseListener listener) {
        ExtSdkApiJni.addListener(listener);
    }

    @Override
    public void delListener(@NonNull ExtSdkBaseListener listener) {
        ExtSdkApiJni.delListener(listener);
    }

    @Override
    public void callCppApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtSdkCallback callback) {
        // todo: work_count: 100+
        // todo: Dart translate Object 100+
        // todo: Javascript translate string or object ??? 100+
        ExtSdkApiJni.callJniApi(methodType, params, callback);
    }

    private static String Tag = "ExtSdkApiFlutter";
}
