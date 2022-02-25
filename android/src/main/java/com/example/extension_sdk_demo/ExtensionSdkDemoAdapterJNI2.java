package com.example.extension_sdk_demo;

import android.util.Log;

// 通过该封装层间接调用原生SDK接口
public class ExtensionSdkDemoAdapterJNI2 {
    private static class SingleHolder {
        static ExtensionSdkDemoAdapterJNI2 instance = new ExtensionSdkDemoAdapterJNI2();
    }

    public static ExtensionSdkDemoAdapterJNI2 getInstance() {
        return ExtensionSdkDemoAdapterJNI2.SingleHolder.instance;
    }

    public void adapterNativeInit(ExtensionSdkDemoAdapterJNIListener2 listener2) {
        Log.i(TAG, "adapterNativeInit");
        // todo: 调用原生接口
        this.listener2 = listener2;// 假设已经从原生SDK返回
    }

    public void adapterNativeHello() {
        Log.i(TAG, "adapterNativeHello");
        // todo: 调用原生接口
        listener2.adapterNativeHelloEcho();// 假设已经从原生SDK返回
    }

    public void adapterNativeSendMessage(int number, String string) {
        Log.i(TAG, "adapterNativeSendMessage");
        // todo: 调用原生接口
        listener2.adapterNativeSendMessageEcho(number, string);
    }

    public void adapterNativeSendMessageWithJson(int number, String json) {
        Log.i(TAG, "adapterNativeSendMessageWithJson");
        // todo: 调用原生接口
        listener2.adapterNativeSendMessageWithJsonEcho(number, json);
    }

    public void adapterNativeSendMessageWithPB(int number, byte[] bytes) {
        Log.i(TAG, "adapterNativeSendMessageWithPB");
        // todo: 调用原生接口
        listener2.adapterNativeSendMessageWithPBEcho(number, bytes);
    }

    private static String TAG = "ExtensionSdkDemoAdapterJNI2";
    private ExtensionSdkDemoAdapterJNIListener2 listener2;
}
