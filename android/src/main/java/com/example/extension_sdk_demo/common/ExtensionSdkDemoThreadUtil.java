package com.example.extension_sdk_demo.common;

import android.os.Handler;
import android.os.Looper;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ExtensionSdkDemoThreadUtil {

    public static void asyncExecute(Runnable runnable) {
//        asyncThreadPool.submit(runnable);
        asyncThreadPool.execute(runnable);
    }

    public static void mainThreadExecute(Runnable runnable) {
        mainThreadHandler.post(runnable);
    }

    private static String TAG = "ExtensionSdkDemoThreadUtil";
    private static ExecutorService asyncThreadPool = Executors.newCachedThreadPool();
    private static Handler mainThreadHandler = new Handler(Looper.getMainLooper());
}
