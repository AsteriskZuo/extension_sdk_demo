package com.example.extension_sdk_demo.common;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

/// 需要各个框架实现自己的版本
/// 该对象的调用者是各个平台架构，所以，省略了工厂模式
public interface ExtensionSdkDemoApi {

    public void init(@NonNull Object config);

    public void unInit(@Nullable Object params);

    public void addListener(@NonNull ExtensionSdkDemoBaseListener listener);

    /**
     * 调用者: 适配层接口
     * 被调用者: C++接口
     * 不同框架(flutter, react-native, unity etc.)参数和回调可能都不相同。
     * 向服务器请求类型的调用请使用此api
     *
     * @param methodType 必填，具体方法类型名称
     * @param params     选填，后续确定。可以是空，map，json, pb字符串等。
     * @param callback   选填，不关注结果可以为空
     */
    public void callCppApi(@NonNull ExtensionSdkDemoMethodTypeE methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback);

    /**
     * 向本地SDK请求设置的调用请使用此api
     *
     * @param methodType 必填，具体方法类型名称
     * @param params 选填，后续确定。可能是监听器、配置信息、初始化信息等。
     * @param callback 选填，不关注结果可以为空
     */
    public void callCppSet(@NonNull ExtensionSdkDemoMethodTypeE methodType, @Nullable Object params, @Nullable ExtensionSdkDemoCallback callback);
}
