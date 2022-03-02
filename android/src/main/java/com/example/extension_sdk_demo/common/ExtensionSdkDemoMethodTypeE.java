package com.example.extension_sdk_demo.common;

// https://howtodoinjava.com/java/enum/java-enum-string-example/

/// 原生方法映射枚举值
public enum ExtensionSdkDemoMethodTypeE {
    METHOD_NONE("no_exist"),
    METHOD_HELLO("native_hello"),
    METHOD_INIT("native_init"),
    METHOD_LOGIN("native_login"),
    METHOD_LOGOUT("native_logout");

    private final String method;

    ExtensionSdkDemoMethodTypeE(String method) {
        this.method = method;
    }

    public String getMethod() {
        return method;
    }

    public static ExtensionSdkDemoMethodTypeE getMethodE(String method) {
        for (ExtensionSdkDemoMethodTypeE value : ExtensionSdkDemoMethodTypeE.values()) {
            if (value.getMethod().equals(method)) {
                return value;
            }
        }
        return METHOD_NONE;
    }

    // 这种方法在android肯定是不行的。代码需要运行在模拟器或者真机上才能进行测试。
//    public static void main(String[] args) {
//        for (ExtensionSdkDemoMethodTypeE methodE : ExtensionSdkDemoMethodTypeE.values()) {
//            Log.i("", methodE.name() + ":" + methodE.getMethod());
//        }
//    }
}
