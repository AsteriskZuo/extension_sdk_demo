package com.example.extension_sdk_demo.sdk;

import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.common.ExtensionSdkDemoCallback;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoMethodTypeE;
import com.example.extension_sdk_demo.flutter.ExtensionSdkDemoMessageListenerFlutter;

public class ExtensionSdkDemoSdkApi {
    public static ExtensionSdkDemoSdkApi getInstance() {
        return instance;
    }

    public void sdkApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback) {
        // todo: 根据方法类型，解析参数，调用回调，调用对应sdk方法
        Log.i(TAG, "api call success");
        callback.success(null);
    }

    public void setListener(@NonNull ExtensionSdkDemoMessageListenerFlutter listener) {
        this.listenerFlutter = listener;
    }

    private static ExtensionSdkDemoSdkApi instance = new ExtensionSdkDemoSdkApi();
    private ExtensionSdkDemoMessageListenerFlutter listenerFlutter;
    private static String TAG = "ExtensionSdkDemoSdkApi";
}
