import 'dart:async';
import 'package:flutter_web_plugins/flutter_web_plugins.dart';
import 'package:flutter_zoom_sdk/zoom_platform_view.dart';
export 'package:flutter_zoom_sdk/zoom_platform_view.dart'
    show ZoomOptions, ZoomMeetingOptions;

/// Web Function For Zoom Sdk for Flutter Web Implementation
class ZoomViewWeb extends ZoomPlatform {
  StreamController<dynamic>? streamController;

  static void registerWith(Registrar registrar) {
    ZoomPlatform.instance = ZoomViewWeb();
  }
}
