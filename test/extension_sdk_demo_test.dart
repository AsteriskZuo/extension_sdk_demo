import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:extension_sdk_demo/extension_sdk_demo.dart';

void main() {
  const MethodChannel channel = MethodChannel('extension_sdk_demo');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await ExtensionSdkDemo.platformVersion, '42');
  });
}
