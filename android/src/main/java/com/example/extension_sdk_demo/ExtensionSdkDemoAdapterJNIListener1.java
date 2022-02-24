package com.example.extension_sdk_demo;

import android.util.Log;

// 通过该接口，监听从C++封装层返回的消息
public class ExtensionSdkDemoAdapterJNIListener1 {
    public void adapterNativeHelloEcho() {
        Log.i(TAG, "adapterNativeHelloEcho");
    }

    public void adapterNativeSendMessageEcho(int number, String string) {
        Log.i(TAG, "adapterNativeSendMessageEcho");
    }

    public void adapterNativeSendMessageWithJsonEcho(int number, String json) {
        Log.i(TAG, "adapterNativeSendMessageWithJsonEcho");
    }

    public void adapterNativeSendMessageWithPBEcho(int number, byte[] bytes) {
        Log.i(TAG, "adapterNativeSendMessageWithPBEcho");
    }

    private static String TAG = "ExtensionSdkDemoAdapterJNIListener1";
}
