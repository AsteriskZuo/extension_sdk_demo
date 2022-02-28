package com.example.extension_sdk_demo;

import androidx.annotation.NonNull;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/**
 * ExtensionSdkDemoPlugin
 */
public class ExtensionSdkDemoPlugin implements FlutterPlugin, MethodCallHandler {
    /// The MethodChannel that will the communication between Flutter and native Android
    ///
    /// This local reference serves to register the plugin with the Flutter Engine and unregister it
    /// when the Flutter Engine is detached from the Activity
    private MethodChannel channel;

    static {
        System.loadLibrary("extension_sdk_demo");
    }

    @Override
    public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
        channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "extension_sdk_demo");
        channel.setMethodCallHandler(this);
        ExtensionSdkDemoAdapter1.getInstance().setChannel(channel);
    }

    @Override
    public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
        if (call.method.equals("getPlatformVersion")) {
            result.success("Android " + android.os.Build.VERSION.RELEASE);
        } else if (call.method.equals("native_init")) {
            ExtensionSdkDemoAdapter1.getInstance().init(call, result);
        } else if (call.method.equals("native_hello")) {
            ExtensionSdkDemoAdapter1.getInstance().adapterJavaHello(call, result);
        } else if (call.method.equals("native_send_message")) {
            ExtensionSdkDemoAdapter1.getInstance().adapterJavaSendMessage(call, result);
        } else if (call.method.equals("native_send_message_with_json")) {
            ExtensionSdkDemoAdapter1.getInstance().adapterJavaSendMessageWithJson(call, result);
        } else if (call.method.equals("native_send_message_with_pb")) {
            ExtensionSdkDemoAdapter1.getInstance().adapterJavaSendMessageWithPB(call, result);
        } else {
            result.notImplemented();
        }
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        channel.setMethodCallHandler(null);
    }
}
