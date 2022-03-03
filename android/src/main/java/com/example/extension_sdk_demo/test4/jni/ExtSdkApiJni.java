package com.example.extension_sdk_demo.test4.jni;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.test4.common.ExtSdkBaseListener;
import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;

/// 承接上层调用
public class ExtSdkApiJni {
    public static native void init(@NonNull Object configures);
    public static native void addListener(ExtSdkBaseListener listener);
    public static native void delListener(ExtSdkBaseListener listener);
    public static native void callJniApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtSdkCallback callback);
    public static native void unInit();
}
