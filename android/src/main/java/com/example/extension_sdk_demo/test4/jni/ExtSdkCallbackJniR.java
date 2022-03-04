package com.example.extension_sdk_demo.test4.jni;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;

public class ExtSdkCallbackJniR implements ExtSdkCallback {
    @Override
    public void success(@Nullable Object data) {
        nativeSuccess(nativeObj, methodType, data);
    }

    @Override
    public void fail(@NonNull int code, @Nullable Object ext) {
        nativeFail(nativeObj, methodType, code, ext);
    }

    public void setNativeObj(long obj) {
        nativeObj = obj;
    }

    public long getNativeObj() {
        return nativeObj;
    }

    public void setMethodType(String methodType) {
        this.methodType = methodType;
    }

    public String getMethodType() {
        return methodType;
    }

    public native void nativeSuccess(long obj, String methodType, @Nullable Object data);
    public native void nativeFail(long obj, String methodType, @NonNull int code, @Nullable Object ext);

    private long nativeObj;
    private String methodType;
}
