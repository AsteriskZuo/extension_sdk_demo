package com.example.extension_sdk_demo;

public class ExtensionSdkDemoAdapterJNI1 {
    private static class SingleHolder {
        static ExtensionSdkDemoAdapterJNI1 instance = new ExtensionSdkDemoAdapterJNI1();
    }

    public static ExtensionSdkDemoAdapterJNI1 getInstance() {
        return ExtensionSdkDemoAdapterJNI1.SingleHolder.instance;
    }

    public native void adapterNativeHello();
    public native void adapterNativeSendMessage(int number, String string);
    public native void adapterNativeSendMessageWithJson(int number, String json);
    public native void adapterNativeSendMessageWithPB(int number, byte[] bytes);

    private static String TAG = "ExtensionSdkDemoAdapterJNI1";
}