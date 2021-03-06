$NetBSD$

Do not compare character pointers with integers.

--- lib/pdf/xpdf/GlobalParams.cc.orig	2012-04-08 17:26:34.000000000 +0000
+++ lib/pdf/xpdf/GlobalParams.cc
@@ -922,9 +922,9 @@ void GlobalParams::parseFile(GString *fi
     char* p = pos1>pos2?pos1:pos2;
     int pos = p ? p-cfgFileName : -1;
     GString*path = new GString(new GString(cfgFileName), 0, (pos < 0 ? strlen(cfgFileName): pos));
-    if(pos1>=0)
+    if(pos1 != NULL)
 	path->append('/');
-    else if(pos2>=0)
+    else if(pos2 != NULL)
 	path->append('\\');
     else
 #ifdef WIN32
