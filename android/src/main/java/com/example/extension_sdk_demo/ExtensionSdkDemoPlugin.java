package com.example.extension_sdk_demo;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.extension_sdk_demo.common.ExtensionSdkDemoCallback;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoMethodTypeE;
import com.example.extension_sdk_demo.common.ExtensionSdkDemoThreadUtil;
import com.example.extension_sdk_demo.flutter.ExtensionSdkDemoApiFlutter;
import com.example.extension_sdk_demo.test4.common.ExtSdkCallback;
import com.example.extension_sdk_demo.test4.common.ExtSdkMethodType;
import com.example.extension_sdk_demo.test4.common.ExtSdkThreadUtil;
import com.example.extension_sdk_demo.test4.flutter.ExtSdkApiFlutter;

import java.util.HashMap;
import java.util.Map;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/**
 * ExtensionSdkDemoPlugin
 * 该框架是flutter平台独有的
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
        if (1 == ExtensionSdkDemoMethod.method || 2 == ExtensionSdkDemoMethod.method) {
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
            } else if (call.method.equals("native_callback")) {
                ExtensionSdkDemoAdapter1.getInstance().adapterJavaCallback(call, result);
            } else {
                result.notImplemented();
            }
        } else if (3 == ExtensionSdkDemoMethod.method) {
            if (call.method.equals("getPlatformVersion")) {
                result.success("Android " + android.os.Build.VERSION.RELEASE);
                return;
            }
            Integer test = new Integer(100);
            Map params = new HashMap();
//            params.put("key", "value");
//            Object value = params.get("key");
            ExtensionSdkDemoMethodTypeE methodType = ExtensionSdkDemoMethodTypeE.getMethodE(call.method);
            if (methodType.equals(ExtensionSdkDemoMethodTypeE.METHOD_NONE)) {
                result.error("100", "This type is not support", null);
                return;
            } else if (methodType.equals(ExtensionSdkDemoMethodTypeE.METHOD_INIT)) {
                // todo: 处理参数
                ExtensionSdkDemoApiFlutter.getInstance().init(new Object());
                result.success(null);
                return;
            } else if (methodType.equals(ExtensionSdkDemoMethodTypeE.METHOD_HELLO)) {
                // todo: 处理参数
//                result.success(null);
//                return;
            } else if (methodType.equals(ExtensionSdkDemoMethodTypeE.METHOD_LOGIN)) {
                // todo: 处理参数
            } else if (methodType.equals(ExtensionSdkDemoMethodTypeE.METHOD_LOGOUT)) {
                result.error("100", "This type is not support", null);
                return;
            }
            ExtensionSdkDemoApiFlutter.getInstance().callCppApi(methodType, params, new ExtensionSdkDemoCallback() {
                @Override
                public void success(@Nullable Object data) {
                    ExtensionSdkDemoThreadUtil.mainThreadExecute(() -> {
                        result.success(Boolean.valueOf(true));
                    });
                }

                @Override
                public void fail(@NonNull int code, @Nullable Object ext) {
                    ExtensionSdkDemoThreadUtil.mainThreadExecute(() -> {
                        result.error(String.valueOf(code), ext.toString(), null);
                    });
                }
            });
        } else if (4 == ExtensionSdkDemoMethod.method) {
            if (call.method.equals("getPlatformVersion")) {
                result.success("Android " + android.os.Build.VERSION.RELEASE);
                return;
            }
            ExtSdkApiFlutter.getInstance().callCppApi(call.method, call.arguments, new ExtSdkCallback() {
                @Override
                public void success(@Nullable Object data) {
                    ExtSdkThreadUtil.mainThreadExecute(()->{
                        if (call.method.equals(ExtSdkMethodType.METHOD_HELLO)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_INIT)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_ADD_LISTENER)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_LOGIN)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_LOGOUT)) {

                        } else {
                            result.notImplemented();
                        }
                    });
                }

                @Override
                public void fail(@NonNull int code, @Nullable Object ext) {
                    ExtSdkThreadUtil.mainThreadExecute(()->{
                        if (call.method.equals(ExtSdkMethodType.METHOD_HELLO)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_INIT)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_ADD_LISTENER)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_LOGIN)) {

                        } else if (call.method.equals(ExtSdkMethodType.METHOD_LOGOUT)) {

                        } else {
                            result.notImplemented();
                        }
                    });
                }
            });
        } else {
            result.notImplemented();
        }
    }

    @Override
    public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
        channel.setMethodCallHandler(null);
    }
}
