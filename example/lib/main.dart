import 'dart:developer';

import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:extension_sdk_demo/extension_sdk_demo.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> implements ExtensionSdkDemoListener {
  static int _count = 0;
  String _platformVersion = 'Unknown';
  String _echoHello = "hello";
  String _echoSendMessage = "send msg success";
  String _echoSendMessageWithJson = "send msg success";
  // String _echoSendMessageWithPB = "send msg success";

  _MyAppState() {
    log("_MyAppState");
    ExtensionSdkDemo.init(this);
  }

  @override
  void dartHelloEcho() {
    log("dartHelloEcho");
    setState(() {
      _echoHello = "success" + _count.toString();
      ++_count;
    });
  }

  @override
  void dartSendMessageEcho(arguments) {
    log("dartSendMessageEcho");
    setState(() {
      _echoSendMessage = "success" + _count.toString();
      ++_count;
    });
  }

  @override
  void dartSendMessageWithJsonEcho(arguments) {
    log("dartSendMessageWithJsonEcho");
    setState(() {
      _echoSendMessageWithJson = "success" + _count.toString();
      ++_count;
    });
  }

  @override
  void dartSendMessageWithPBEcho(arguments) {
    log("dartSendMessageWithPBEcho");
    // setState(() {
    //   _echoSendMessageWithPB = "success" + _count.toString();
    //   ++_count;
    // });
  }

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    String platformVersion;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      platformVersion =
          await ExtensionSdkDemo.platformVersion ?? 'Unknown platform version';
    } on PlatformException {
      platformVersion = 'Failed to get platform version.';
    }

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _platformVersion = platformVersion;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
          appBar: AppBar(
            title: const Text('Plugin example app'),
          ),
          body: Column(
            children: [
              Text('Running on: $_platformVersion\n'),
              Row(
                children: [
                  TextButton(
                      onPressed: () {
                        ExtensionSdkDemo.dartHello();
                      },
                      child: const Text('hello')),
                  Text(_echoHello)
                ],
              ),
              Row(
                children: [
                  TextButton(
                      onPressed: () {
                        ExtensionSdkDemo.dartSendMessage(1, "string");
                      },
                      child: const Text('send message with param')),
                  Text(_echoSendMessage)
                ],
              ),
              Row(
                children: [
                  TextButton(
                      onPressed: () {
                        ExtensionSdkDemo.dartSendMessageWithJson('''
{
  "number" : 1,
  "string" : "send message"
}
''');
                      },
                      child: const Text('send message with json')),
                  Text(_echoSendMessageWithJson)
                ],
              ),
              Row(
                children: [
                  TextButton(
                      onPressed: () {
                        // TODO:
                      },
                      child: const Text('send message with pb')),
                  const Text('echo result')
                ],
              ),
            ],
          )),
    );
  }
}
