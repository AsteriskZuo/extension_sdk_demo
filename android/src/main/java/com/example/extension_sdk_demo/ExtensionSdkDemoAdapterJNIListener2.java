package com.example.extension_sdk_demo;

import android.util.Log;

// 通过继承原生SDK的监听接口，接收消息
public class ExtensionSdkDemoAdapterJNIListener2 {
    public void adapterNativeHelloEcho() {
        Log.i(TAG, "adapterNativeHelloEcho");
        nativeHelloEcho();
    }

    public void adapterNativeSendMessageEcho(int number, String string) {
        Log.i(TAG, "adapterNativeSendMessageEcho");
        nativeSendMessageEcho(number, string);
    }

    public void adapterNativeSendMessageWithJsonEcho(int number, String json) {
        Log.i(TAG, "adapterNativeSendMessageWithJsonEcho");
        nativeSendMessageWithJsonEcho(number, json);
    }

    public void adapterNativeSendMessageWithPBEcho(int number, byte[] bytes) {
        Log.i(TAG, "adapterNativeSendMessageWithPBEcho");
        nativeSendMessageWithPBEcho(number, bytes);
    }

    public native void nativeHelloEcho();

    public native void nativeSendMessageEcho(int number, String string);

    public native void nativeSendMessageWithJsonEcho(int number, String json);

    public native void nativeSendMessageWithPBEcho(int number, byte[] bytes);

    private static String TAG = "ExtensionSdkDemoAdapterJNIListener2";
}
