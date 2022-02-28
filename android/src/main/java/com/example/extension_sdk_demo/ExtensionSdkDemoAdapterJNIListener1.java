package com.example.extension_sdk_demo;

import android.util.Log;

// 通过该接口，监听从C++封装层返回的消息
public class ExtensionSdkDemoAdapterJNIListener1 {
    ExtensionSdkDemoAdapterJNIListener1(ExtensionSdkDemoCallback1 callback1) {
        Log.i(TAG, "ExtensionSdkDemoAdapterJNIListener1");
        this.callback1 = callback1;
    }
    public void adapterNativeHelloEcho() {
        Log.i(TAG, "adapterNativeHelloEcho");
//        ExtensionSdkDemoAdapter1.getInstance().getCallback1().callbackJavaHello();
        callback1.callbackJavaHello();
    }

    public void adapterNativeSendMessageEcho(int number, String string) {
        Log.i(TAG, "adapterNativeSendMessageEcho");
//        ExtensionSdkDemoAdapter1.getInstance().getCallback1().callbackJavaSendMessage(number, string);
        callback1.callbackJavaSendMessage(number, string);
    }

    public void adapterNativeSendMessageWithJsonEcho(int number, String json) {
        Log.i(TAG, "adapterNativeSendMessageWithJsonEcho");
//        ExtensionSdkDemoAdapter1.getInstance().getCallback1().callbackJavaSendMessageWithJson(number, json);
        callback1.callbackJavaSendMessageWithJson(number, json);
    }

    public void adapterNativeSendMessageWithPBEcho(int number, byte[] bytes) {
        Log.i(TAG, "adapterNativeSendMessageWithPBEcho");
//        ExtensionSdkDemoAdapter1.getInstance().getCallback1().callbackJavaSendMessageWithPB(number, bytes);
        callback1.callbackJavaSendMessageWithPB(number, bytes);
    }

    private static String TAG = "ExtensionSdkDemoAdapterJNIListener1";
    private ExtensionSdkDemoCallback1 callback1;
}
