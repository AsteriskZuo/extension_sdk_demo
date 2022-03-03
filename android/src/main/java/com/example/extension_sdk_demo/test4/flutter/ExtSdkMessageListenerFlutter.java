package com.example.extension_sdk_demo.test4.flutter;

import android.util.Log;

import com.example.extension_sdk_demo.test4.common.ExtSdkMessageListener;

public class ExtSdkMessageListenerFlutter implements ExtSdkMessageListener {
    @Override
    public void onNewMessages(Object list) {
        Log.i(TAG, "onNewMessages");
    }
    private static String TAG = "ExtSdkMessageListenerFlutter";
}
