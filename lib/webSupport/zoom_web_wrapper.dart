import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'package:universal_html/html.dart' as html;
import "package:flutter_zoom_sdk/webSupport/platform_view_registry.dart";


class ZoomWebWrapper extends StatefulWidget {
  final Widget child;
  final VoidCallback onCompleted;

  const ZoomWebWrapper({
    Key? key,
    required this.child,
    required this.onCompleted,
  }) : super(key: key);

  @override
  State<ZoomWebWrapper> createState() => _ZoomWebWrapperState();
}

class _ZoomWebWrapperState extends State<ZoomWebWrapper> {
  final String zoomViewType = "zoomViewType";

  bool isVisible = false;

  final mDiv = html.DivElement()..id = 'meetingSDKElement';

  @override
  void initState() {
    super.initState();
    platformViewRegistry.registerViewFactory(
      zoomViewType,
      (int viewId) => mDiv,
    );
    setState(() {});
    onChildNodeAdded(mDiv, (childElement) {
      if (childElement.innerHtml != null) {
        if (childElement.innerHtml!.contains("The meeting has not started") ||
            childElement.innerHtml!.contains("Waiting for meeting to start") ||
            childElement.innerHtml!.contains("Connecting...")) {
          isVisible = true;
        } else if (childElement.innerHtml!
                .contains("Meeting Disconnected: Leave Meeting") ||
            childElement.innerHtml!
                .contains("This meeting has been ended by host")) {
          widget.onCompleted();
          isVisible = false;
        }
      } else {
        isVisible = false;
      }
      setState(() {});
    });
  }

  @override
  Widget build(BuildContext context) {
    return kIsWeb
        ? Stack(
            children: [
              widget.child,
              IgnorePointer(
                ignoring: !isVisible,
                child: HtmlElementView(
                  viewType: zoomViewType,
                ),
              ),
            ],
          )
        : widget.child;
  }

  void onChildNodeAdded(html.Element parent, Function(html.Element) callback) {
    // final observer = MutationObserver((mutations, observer) {
    //   for (final mutation in mutations) {
    //     for (final node in mutation.addedNodes) {
    //       if (node is html.Element) {
    //         callback(node);
    //       }
    //     }
    //   }
    // });

    //observer.observe(parent, childList: true, subtree: true);
  }

  html.Element justifyElement(html.Element element) {
    element.parent?.style.display = 'flex';
    element.parent?.style.justifyContent = 'center';
    element.parent?.style.alignItems = 'center';
    element.parent?.style.display = 'inline-block';
    return element;
  }
}
