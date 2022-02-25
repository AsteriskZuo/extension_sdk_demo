package com.example.extension_sdk_demo;

// 通过该转换接口，调用C++封装层
public class ExtensionSdkDemoAdapterJNI1 {


    private static class SingleHolder {
        static ExtensionSdkDemoAdapterJNI1 instance = new ExtensionSdkDemoAdapterJNI1();
    }

    public static ExtensionSdkDemoAdapterJNI1 getInstance() {
        return ExtensionSdkDemoAdapterJNI1.SingleHolder.instance;
    }

    public void setListener(ExtensionSdkDemoCallback1 extensionSdkDemoCallback1) {
        ExtensionSdkDemoAdapterJNIListener1 listener1 = new ExtensionSdkDemoAdapterJNIListener1(extensionSdkDemoCallback1);
        adapterNativeInit(listener1);
    }

    public native void adapterNativeInit(ExtensionSdkDemoAdapterJNIListener1 listener1);

    public native void adapterNativeHello();

    public native void adapterNativeSendMessage(int number, String string);

    public native void adapterNativeSendMessageWithJson(int number, String json);

    public native void adapterNativeSendMessageWithPB(int number, byte[] bytes);

    private static String TAG = "ExtensionSdkDemoAdapterJNI1";
    private ExtensionSdkDemoAdapterJNIListener1 listener1;
}
