package com.example.extension_sdk_demo;

import android.util.Log;

import java.util.HashMap;
import java.util.Map;

// 调用原生 SDK 接口
public class ExtensionSdkDemoAdapter1Method2 {
    private static class SingleHolder {
        static ExtensionSdkDemoAdapter1Method2 instance = new ExtensionSdkDemoAdapter1Method2();
    }

    public static ExtensionSdkDemoAdapter1Method2 getInstance() {
        return ExtensionSdkDemoAdapter1Method2.SingleHolder.instance;
    }

    public void setListener(ExtensionSdkDemoCallback1 listener) {
        this.listener = new ExtensionSdkDemoAdapter1Method2Callback(listener);
    }

    public  void adapterHello() {
        Log.i(TAG, "adapterHello");
        // todo: 调用原生SDK 接口
        listener.helloEcho();// todo: 模拟从原生返回
    }

    public  void adapterSendMessage(int number, String string) {
        Log.i(TAG, "adapterSendMessage");
        // todo: 调用原生SDK 接口
        listener.sendMessageEcho(number, string);// todo: 模拟从原生返回
    }

    public  void adapterSendMessageWithJson(int number, String json) {
        Log.i(TAG, "adapterSendMessageWithJson");
        // todo: 调用原生SDK 接口
        listener.sendMessageWithJsonEcho(number, json);// todo: 模拟从原生返回
    }

    public  void adapterSendMessageWithPB(int number, byte[] bytes) {
        Log.i(TAG, "adapterSendMessageWithPB");
        // todo: 调用原生SDK 接口
        listener.sendMessageWithPBEcho(number, bytes);// todo: 模拟从原生返回
    }

    private static String TAG = "ExtensionSdkDemoAdapter1Method2";
    private ExtensionSdkDemoAdapter1Method2Callback listener;
}

// 从原生 SDK 接口返回
class ExtensionSdkDemoAdapter1Method2Callback {

    ExtensionSdkDemoAdapter1Method2Callback(ExtensionSdkDemoCallback1 listener) {
        this.listener = listener;
    }
    public void helloEcho() {
        Log.i(TAG, "helloEcho");
        listener.callbackJavaHello();
    }

    public void sendMessageEcho(int number, String string) {
        Log.i(TAG, "sendMessageEcho");
        listener.callbackJavaSendMessage(number, string);
    }

    public void sendMessageWithJsonEcho(int number, String json) {
        Log.i(TAG, "sendMessageWithJsonEcho");
        listener.callbackJavaSendMessageWithJson(number, json);
    }

    public void sendMessageWithPBEcho(int number, byte[] pb) {
        Log.i(TAG, "sendMessageWithPBEcho");
        listener.callbackJavaSendMessageWithPB(number, pb);
    }

    private static String TAG = "ExtensionSdkDemoAdapter1Method2Callback";
    private ExtensionSdkDemoCallback1 listener;
}