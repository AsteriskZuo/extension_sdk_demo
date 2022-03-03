package com.example.extension_sdk_demo.test4.common;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public interface ExtSdkApi {

    void init(@NonNull Object config);

    void unInit(@Nullable Object params);

    void addListener(@NonNull ExtSdkBaseListener listener);

    void delListener(@NonNull ExtSdkBaseListener listener);

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
    void callCppApi(@NonNull String methodType, @Nullable Object params, @Nullable ExtSdkCallback callback);
}
