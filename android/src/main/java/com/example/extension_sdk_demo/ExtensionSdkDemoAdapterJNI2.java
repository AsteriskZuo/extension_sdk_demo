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
    }

    public void adapterNativeHello() {
        Log.i(TAG, "adapterNativeHello");
        // todo: 调用原生接口
    }

    public void adapterNativeSendMessage(int number, String string){
        Log.i(TAG, "adapterNativeSendMessage");
        // todo: 调用原生接口
    }

    public void adapterNativeSendMessageWithJson(int number, String json) {
        Log.i(TAG, "adapterNativeSendMessageWithJson");
        // todo: 调用原生接口
    }

    public void adapterNativeSendMessageWithPB(int number, byte[] bytes) {
        Log.i(TAG, "adapterNativeSendMessageWithPB");
        // todo: 调用原生接口
    }

    private static String TAG = "ExtensionSdkDemoAdapterJNI2";
}
