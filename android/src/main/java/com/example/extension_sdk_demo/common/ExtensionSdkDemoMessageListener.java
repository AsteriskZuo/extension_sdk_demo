package com.example.extension_sdk_demo.common;

import java.util.List;

/// 更多的listener，这是一个示例
public interface ExtensionSdkDemoMessageListener extends ExtensionSdkDemoBaseListener {
    public void onNewMessages(Object list);
}
