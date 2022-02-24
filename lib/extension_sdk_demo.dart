import 'dart:async';
import 'dart:developer';
import 'dart:typed_data';

import 'package:flutter/services.dart';

class ExtensionSdkDemo {
  static const MethodChannel _channel = MethodChannel('extension_sdk_demo');
  static late ExtensionSdkDemoListener _listener;

  static void init(ExtensionSdkDemoListener listener) {
    _listener = listener;
    _channel.setMethodCallHandler((call) async => {
          if (call.method == "dart_hello_echo")
            {_listener.dartHelloEcho()}
          else if (call.method == "dart_send_message_echo")
            {_listener.dartSendMessageEcho(call.arguments)}
          else if (call.method == "dart_send_message_with_json_echo")
            {_listener.dartSendMessageWithJsonEcho(call.arguments)}
          else if (call.method == "dart_send_message_with_pb_echo")
            {_listener.dartSendMessageWithPBEcho(call.arguments)}
          else
            {log('nothing')}
        });
  }

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  static Future<bool> dartHello() async {
    final bool result = await _channel.invokeMethod('native_hello');
    return result;
  }

  static Future<bool> dartSendMessage(int number, String string) async {
    final bool result = await _channel.invokeMethod('native_send_message');
    return result;
  }

  static Future<bool> dartSendMessageWithJson(String json) async {
    final bool result =
        await _channel.invokeMethod('native_send_message_with_json');
    return result;
  }

  /// warning: 不建议对外暴露pb技术
  static Future<bool> dartSendMessageWithPB(Uint8List byte) async {
    final bool result =
        await _channel.invokeMethod('native_send_message_with_pb');
    return result;
  }
}

abstract class ExtensionSdkDemoListener {
  void dartHelloEcho();

  void dartSendMessageEcho(dynamic arguments);

  void dartSendMessageWithJsonEcho(dynamic arguments);

  void dartSendMessageWithPBEcho(dynamic arguments);
}
