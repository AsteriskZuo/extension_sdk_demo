package com.example.extension_sdk_demo.common;

/// 参数类型: 方便以后参数的灵活性和扩展性
public enum ExtensionSdkDemoParamsTypeE {
    PARAMS_JSON("json"),
    PARAMS_Object("object"),
    PARAMS_PB("proto");

    private final String paramsType;

    ExtensionSdkDemoParamsTypeE(String type) {
        this.paramsType = type;
    }

    public String getParamsType() {
        return paramsType;
    }
}
