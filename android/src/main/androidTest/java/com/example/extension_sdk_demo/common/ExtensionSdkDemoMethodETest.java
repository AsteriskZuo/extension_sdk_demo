package com.example.extension_sdk_demo.common;

import static com.google.common.truth.Truth.assertThat;

import android.util.Log;

import androidx.test.ext.junit.runners.AndroidJUnit4;
import androidx.test.filters.SmallTest;

import com.example.extension_sdk_demo.commcon.ExtensionSdkDemoMethodE;

import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(AndroidJUnit4.class)
@SmallTest
public class ExtensionSdkDemoMethodETest {
    @Test
    public void test_hello() {
        Log.i(TAG, "test_hello");
    }
    @Test
    public void test_for() {
        ExtensionSdkDemoMethodE obj = ExtensionSdkDemoMethodE.METHOD_HELLO;
        String method = obj.getMethod();
        String name = obj.name();
        Log.i(TAG, method + ":" + name);
        assertThat(method).isEqualTo("test_hello");
        assertThat(method).isEqualTo("native_hello");
    }

    private String TAG = "ExtensionSdkDemoMethodETest";
}
