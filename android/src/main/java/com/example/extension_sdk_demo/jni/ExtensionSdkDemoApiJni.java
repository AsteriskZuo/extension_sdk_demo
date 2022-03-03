package com.example.extension_sdk_demo.jni;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.common.ExtensionSdkDemoBaseListener;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoCallback;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoMethodTypeE;

public class ExtensionSdkDemoApiJni {
    public static native void init(@NonNull Object configures);
    public static native void callJniApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback);
    public static native void setListener(ExtensionSdkDemoBaseListener listener);
}
