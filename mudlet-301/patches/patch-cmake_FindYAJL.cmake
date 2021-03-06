$NetBSD$
Swap out /usr/local with @PREFIX@
--- cmake/FindYAJL.cmake.orig	2017-07-11 00:01:53.000000000 +0000
+++ cmake/FindYAJL.cmake
@@ -12,7 +12,7 @@ FIND_PATH(YAJL_INCLUDE_DIR yajl/yajl_ver
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw # Fink
   /opt/local # DarwinPorts
@@ -28,7 +28,7 @@ FIND_LIBRARY(YAJL_LIBRARY_RELEASE 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
@@ -44,7 +44,7 @@ FIND_LIBRARY(YAJL_LIBRARY_DEBUG 
   PATHS
   ~/Library/Frameworks
   /Library/Frameworks
-  /usr/local
+  @PREFIX@
   /usr
   /sw
   /opt/local
