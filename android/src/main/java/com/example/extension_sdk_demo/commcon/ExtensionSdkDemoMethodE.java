package com.example.extension_sdk_demo.commcon;

import android.util.Log;

// https://howtodoinjava.com/java/enum/java-enum-string-example/

public enum ExtensionSdkDemoMethodE {
    METHOD_HELLO("native_hello");

    private final String method;

    ExtensionSdkDemoMethodE(String method) {
        this.method = method;
    }

    public String getMethod() {
        return method;
    }

//    public static void main(String[] args) {
//        for (ExtensionSdkDemoMethodE methodE : ExtensionSdkDemoMethodE.values()) {
//            Log.i("", methodE.name() + ":" + methodE.getMethod());
//        }
//    }
}
