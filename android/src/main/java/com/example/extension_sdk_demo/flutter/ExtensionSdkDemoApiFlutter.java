package com.example.extension_sdk_demo.flutter;

import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.common.ExtensionSdkDemoApi;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoBaseListener;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoCallback;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoMethodTypeE;
import com.example.extension_sdk_demo.jni.ExtensionSdkDemoApiJni;

public class ExtensionSdkDemoApiFlutter implements ExtensionSdkDemoApi {

    public static ExtensionSdkDemoApiFlutter getInstance() {
        return instance;
    }

    @Override
    public void init(@NonNull Object config) {
        Log.i(TAG, "init");
        ExtensionSdkDemoApiJni.init(config);
        this.addListener(new ExtensionSdkDemoMessageListenerFlutter());
    }

    @Override
    public void unInit(@Nullable Object params) {
        Log.i(TAG, "unInit");
    }

    @Override
    public void addListener(@NonNull ExtensionSdkDemoBaseListener listener) {
        Log.i(TAG, listener.getClass().getName());
        ExtensionSdkDemoApiJni.setListener(listener);
    }

    @Override
    public void callCppApi(@NonNull ExtensionSdkDemoMethodTypeE methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback) {
        Log.i(TAG, "callCppApi");
        ExtensionSdkDemoApiJni.callJniApi(methodType.getMethod(), params, callback);
    }

    @Override
    public void callCppSet(@NonNull ExtensionSdkDemoMethodTypeE methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback) {
        Log.i(TAG, "callCppSet");
        ExtensionSdkDemoApiJni.callJniApi(methodType.getMethod(), params, callback);
    }

    private static ExtensionSdkDemoApiFlutter instance = new ExtensionSdkDemoApiFlutter();
    private static String TAG = "ExtensionSdkDemoApiFlutter";
}
