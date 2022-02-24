package com.example.extension_sdk_demo;

import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import androidx.annotation.NonNull;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.function.Function;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;

public class ExtensionSdkDemoAdapter1 {
    public void setChannel(MethodChannel channel) {
        this.channel = channel;
    }

    public MethodChannel getChannel() {
        return this.channel;
    }

    private static class SingleHolder {
        static ExtensionSdkDemoAdapter1 instance = new ExtensionSdkDemoAdapter1();
    }

    public static ExtensionSdkDemoAdapter1 getInstance() {
        return SingleHolder.instance;
    }

    public void adapterJavaHello(@NonNull MethodCall call, @NonNull MethodChannel.Result result) {
        Log.i(TAG, "adapterJavaHello");
        asyncThreadExec(() -> {
            result.success(Boolean.valueOf(true));
//            ExtensionSdkDemoCallback1.getInstance().callbackJavaHello();//TODO:
        });
    }

    public void adapterJavaSendMessage(@NonNull MethodCall call, @NonNull MethodChannel.Result result) {
        Log.i(TAG, "adapterJavaSendMessage");
        result.success(Boolean.valueOf(true));
    }

    public void adapterJavaSendMessageWithJson(@NonNull MethodCall call, @NonNull MethodChannel.Result result) {
        Log.i(TAG, "adapterJavaSendMessageWithJson");
        result.success(Boolean.valueOf(true));
    }

    public void adapterJavaSendMessageWithPB(@NonNull MethodCall call, @NonNull MethodChannel.Result result) {
        Log.i(TAG, "adapterJavaSendMessageWithPB");
        result.success(Boolean.valueOf(true));
    }

    private void asyncThreadExec(Runnable runnable) {
//        asyncThreadPool.submit(runnable);
        asyncThreadPool.execute(runnable);
    }

    public void uiThreadExec(Runnable runnable) {
        uiThreadHandler.post(runnable);
    }

    private static String TAG = "ExtensionSdkDemoAdapter1";
    private final ExecutorService asyncThreadPool = Executors.newCachedThreadPool();
    private final Handler uiThreadHandler = new Handler(Looper.getMainLooper());
    private MethodChannel channel;
}

class ExtensionSdkDemoCallback1 {
    private static class SingleHolder {
        static ExtensionSdkDemoCallback1 instance = new ExtensionSdkDemoCallback1();
    }

    public static ExtensionSdkDemoCallback1 getInstance() {
        return ExtensionSdkDemoCallback1.SingleHolder.instance;
    }

    public void callbackJavaHello() {
        Log.i(TAG, "callbackJavaHello");
        ExtensionSdkDemoAdapter1.getInstance().uiThreadExec(() -> {
            ExtensionSdkDemoAdapter1.getInstance().getChannel().invokeMethod("dart_hello_echo", null);
        });
    }

    public void callbackJavaSendMessage(int number, String string) {
        Log.i(TAG, "callbackJavaSendMessage");
        ExtensionSdkDemoAdapter1.getInstance().uiThreadExec(() -> {
            Map<String, Object> params = new HashMap<>();
            params.put("number", number);
            params.put("string", string);
            ExtensionSdkDemoAdapter1.getInstance().getChannel().invokeMethod("dart_send_message_echo", params);
        });
    }

    public void callbackJavaSendMessageWithJson(int number, String json) {
        Log.i(TAG, "callbackJavaSendMessageWithJson");
        ExtensionSdkDemoAdapter1.getInstance().uiThreadExec(() -> {
            Map<String, Object> params = new HashMap<>();
            params.put("number", number);
            params.put("json", json);
            ExtensionSdkDemoAdapter1.getInstance().getChannel().invokeMethod("dart_send_message_with_json_echo", params);
        });
    }

    public void callbackJavaSendMessageWithPB(int number, byte[] pb) {
        Log.i(TAG, "callbackJavaSendMessageWithPB");
        ExtensionSdkDemoAdapter1.getInstance().uiThreadExec(() -> {
            Map<String, Object> params = new HashMap<>();
            params.put("number", number);
            params.put("pb", pb.toString()); // todo:
            ExtensionSdkDemoAdapter1.getInstance().getChannel().invokeMethod("dart_send_message_with_pb_echo", params);
        });
    }

    private static String TAG = "ExtensionSdkDemoCallback1";
}