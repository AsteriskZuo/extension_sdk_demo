package com.example.extension_sdk_demo.test4.jni;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;

public class ExtSdkCallbackJniR implements ExtSdkCallback {
    @Override
    public void success(@Nullable Object data) {

    }

    @Override
    public void fail(@NonNull int code, @Nullable Object ext) {

    }

    public native void nativeSuccess(@Nullable Object data);
    public native void nativeFail(@NonNull int code, @Nullable Object ext);
}
