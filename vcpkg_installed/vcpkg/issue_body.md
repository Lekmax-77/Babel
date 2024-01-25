Package: qt5-base:x64-linux@5.15.11#1

**Host Environment**

- Host: x64-linux
- Compiler: GNU 11.4.0
-    vcpkg-tool version: 2023-12-12-1c9ec1978a6b0c2b39c9e9554a96e3e275f7556e
    vcpkg-scripts version: unknown

**To Reproduce**

`vcpkg install `
**Failure logs**

```
CMake Warning at ports/qt5-base/portfile.cmake:4 (message):
  qt5-base currently requires some packages from the system package manager.
  They can be installed on Ubuntu systems via sudo apt-get install
  '^libxcb.*-dev' libx11-xcb-dev libgl1-mesa-dev libxrender-dev libxi-dev
  libxkbcommon-dev libxkbcommon-x11-dev.  For more information, see
  https://doc.qt.io/qt-5/linux.html and
  https://doc.qt.io/qt-5/linux-requirements.html
Call Stack (most recent call first):
  scripts/ports.cmake:170 (include)


-- Figuring out qt target mkspec. Target arch x64
-- Target mkspec set to: linux-g++
-- Host mkspec not set. Qt's own buildsystem will try to figure out the host system
-- Using cached qtbase-everywhere-opensource-src-5.15.11.tar.xz.
-- Cleaning sources at /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/downloads/qtbase-everywhere-opensource-src-5.15.11.tar.xz
-- Applying patch patches/CVE-2023-24607-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-32762-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-32763-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-33285-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-34410-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-37369-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-38197-qtbase-5.15.diff
-- Applying patch patches/CVE-2023-43114-5.15.patch
-- Applying patch patches/winmain_pro.patch
-- Applying patch patches/windows_prf.patch
-- Applying patch patches/qt_app.patch
-- Applying patch patches/gui_configure.patch
-- Applying patch patches/xlib.patch
-- Applying patch patches/egl.patch
-- Applying patch patches/qtbug_96392.patch
-- Applying patch patches/mysql_plugin_include.patch
-- Applying patch patches/mysql-configure.patch
-- Applying patch patches/cocoa.patch
-- Applying patch patches/xcode-15.patch
-- Applying patch patches/patch-qtbase-memory_resource.diff
-- Applying patch patches/Qt5BasicConfig.patch
-- Applying patch patches/Qt5PluginTarget.patch
-- Applying patch patches/create_cmake.patch
-- Applying patch patches/Qt5GuiConfigExtras.patch
-- Applying patch patches/fix_angle.patch
-- Applying patch patches/mingw9.patch
-- Using source at /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean
-- Getting CMake variables for x64-linux
-- Configuring x64-linux-dbg
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:112 (message):
    Command failed: /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/configure -confirm-license -opensource -verbose -system-zlib -system-libjpeg -system-libpng -system-freetype -system-pcre -system-doubleconversion -system-sqlite -system-harfbuzz -no-angle -no-glib -openssl-linked -no-sql-psql -no-sql-mysql --vulkan=no -no-icu -fontconfig -xcb-xlib -xcb -linuxfb -nomake examples -nomake tests -static LIBJPEG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libjpeg.a ZLIB_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a "LIBPNG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a" PCRE2_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpcre2-16.a "FREETYPE_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfreetyped.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbrotlidec.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbrotlicommon.a" QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a "QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a" QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a "SQLITE_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libsqlite3.a -ldl -lpthread" "HARFBUZZ_LIBS=-lharfbuzz -lm -lfreetyped -lbz2d -lpng16d -lz -lbrotlidec -lbrotlicommon -lm" "OPENSSL_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libssl.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libcrypto.a -ldl -lpthread" "FONTCONFIG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfontconfig.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfreetyped.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libexpat.a -luuid" -debug -prefix /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux -hostprefix /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -hostlibdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug/lib -hostbindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug/bin -archdatadir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -datadir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/share/qt5/debug -plugindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/plugins -qmldir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/qml -headerdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -libexecdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -bindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/bin -libdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -I /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -L /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link -platform linux-g++ QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc "QMAKE_CFLAGS_DEBUG+=-fPIC -g" "QMAKE_CXXFLAGS_DEBUG+=-fPIC -g"
    Working Directory: /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg
    Error code: 3
    See logs for more information:
      /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/config-x64-linux-dbg-out.log
      /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/config-x64-linux-dbg-err.log

Call Stack (most recent call first):
  ports/qt5-base/cmake/configure_qt.cmake:186 (vcpkg_execute_required_process)
  ports/qt5-base/portfile.cmake:392 (configure_qt)
  scripts/ports.cmake:170 (include)



```
<details><summary>/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/config-x64-linux-dbg-out.log</summary>

```
Performing shadow build...
Preparing build tree...
Creating qmake...
g++ -c -o main.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/main.cpp
g++ -c -o meta.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/meta.cpp
g++ -c -o option.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/option.cpp
g++ -c -o project.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/project.cpp
g++ -c -o property.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/property.cpp
...
Skipped 80 lines
...
g++ -c -o qvsnprintf.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/text/qvsnprintf.cpp
g++ -c -o qxmlstream.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/serialization/qxmlstream.cpp
g++ -c -o qxmlutils.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/serialization/qxmlutils.cpp
g++ -c -o qcore_unix.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/kernel/qcore_unix.cpp
g++ -c -o qfilesystemengine_unix.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/io/qfilesystemengine_unix.cpp
g++ -c -o qfilesystemiterator_unix.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/io/qfilesystemiterator_unix.cpp
g++ -c -o qfsfileengine_unix.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/io/qfsfileengine_unix.cpp
g++ -c -o qlocale_unix.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/text/qlocale_unix.cpp
g++ -c -o qlibraryinfo.o   -std=c++11 -ffunction-sections -fdata-sections -g -g  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/library -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/3rdparty/tinycbor/src -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/unix -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/win32 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/qmake/generators/mac -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/include/QtCore/5.15.11/QtCore -I../src/corelib/global -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -DQT_VERSION_STR=\"5.15.11\" -DQT_VERSION_MAJOR=5 -DQT_VERSION_MINOR=15 -DQT_VERSION_PATCH=11 -DQT_BUILD_QMAKE -DQT_BOOTSTRAPPED -DPROEVALUATOR_FULL -DQT_NO_FOREACH -DQT_BUILD_QMAKE_BOOTSTRAP /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/src/corelib/global/qlibraryinfo.cpp
g++ -o "../bin/qmake" main.o meta.o option.o project.o property.o ioutils.o proitems.o qmakebuiltins.o qmakeevaluator.o qmakeglobals.o qmakeparser.o qmakevfs.o pbuilder_pbx.o makefile.o makefiledeps.o metamakefile.o projectgenerator.o unixmake2.o unixmake.o mingw_make.o msbuild_objectmodel.o msvc_nmake.o msvc_objectmodel.o msvc_vcproj.o msvc_vcxproj.o winmakefile.o xmloutput.o qutfcodec.o qendian.o qglobal.o qlogging.o qmalloc.o qnumeric.o qoperatingsystemversion.o qrandom.o qabstractfileengine.o qbuffer.o qdatastream.o qdebug.o qdir.o qdiriterator.o qfile.o qfiledevice.o qfileinfo.o qfilesystemengine.o qfilesystementry.o qfsfileengine.o qfsfileengine_iterator.o qiodevice.o qsettings.o qtemporaryfile.o qtextstream.o qcborstreamwriter.o qcborvalue.o qjsoncbor.o qjsonarray.o qjsondocument.o qjsonobject.o qjsonparser.o qjsonvalue.o qmetatype.o qsystemerror.o qvariant.o quuid.o qarraydata.o qbitarray.o qbytearray.o qbytearraylist.o qbytearraymatcher.o qcalendar.o qgregoriancalendar.o qromancalendar.o qcryptographichash.o qdatetime.o qhash.o qlist.o qlocale.o qlocale_tools.o qmap.o qregexp.o qringbuffer.o qstringbuilder.o qstring.o qstringlist.o qversionnumber.o qvsnprintf.o qxmlstream.o qxmlutils.o qcore_unix.o qfilesystemengine_unix.o qfilesystemiterator_unix.o qfsfileengine_unix.o qlocale_unix.o  qlibraryinfo.o   -Wl,--gc-sections
Info: creating cache file /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/.qmake.cache
Info: creating stash file /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/.qmake.stash
```
</details>

<details><summary>/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/config-x64-linux-dbg-err.log</summary>

```
Command line: -confirm-license -opensource -verbose -system-zlib -system-libjpeg -system-libpng -system-freetype -system-pcre -system-doubleconversion -system-sqlite -system-harfbuzz -no-angle -no-glib -openssl-linked -no-sql-psql -no-sql-mysql --vulkan=no -no-icu -fontconfig -xcb-xlib -xcb -linuxfb -nomake examples -nomake tests -static LIBJPEG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libjpeg.a ZLIB_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a 'LIBPNG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' PCRE2_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpcre2-16.a 'FREETYPE_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfreetyped.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbrotlidec.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbrotlicommon.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a 'SQLITE_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libsqlite3.a -ldl -lpthread' 'HARFBUZZ_LIBS=-lharfbuzz -lm -lfreetyped -lbz2d -lpng16d -lz -lbrotlidec -lbrotlicommon -lm' 'OPENSSL_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libssl.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libcrypto.a -ldl -lpthread' 'FONTCONFIG_LIBS=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfontconfig.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libfreetyped.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libexpat.a -luuid' -debug -prefix /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux -hostprefix /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -hostlibdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug/lib -hostbindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug/bin -archdatadir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -datadir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/share/qt5/debug -plugindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/plugins -qmldir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/qml -headerdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -libexecdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/tools/qt5/debug -bindir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/bin -libdir /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -I /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -L /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link -platform linux-g++ QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g'

This is the Qt Open Source Edition.

You have already accepted the terms of the Open Source license.

Running configuration tests...
Checking for machine tuple... 
+ g++ -dumpmachine
> x86_64-linux-gnu
test config.qtbase.tests.machineTuple succeeded
Checking for valid makespec... 
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/verifyspec && /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/bin/qmake "CONFIG -= qt debug_and_release app_bundle lib_bundle" "CONFIG += static warn_off console single_arch" 'QMAKE_LIBDIR += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link' 'INCLUDEPATH += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g' /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/verifyspec
> Info: creating stash file /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/.qmake.stash
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/verifyspec && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -O2 -w -fPIC  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/verifyspec -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o verifyspec.o /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/verifyspec/verifyspec.cpp
> c++ -Wl,-O1 -o verifyspec verifyspec.o   -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link   /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a
test config.qtbase.tests.verifyspec succeeded
Checking for target architecture... 
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/arch && /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/bin/qmake "CONFIG -= qt debug_and_release app_bundle lib_bundle" "CONFIG += static warn_off console single_arch" 'QMAKE_LIBDIR += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link' 'INCLUDEPATH += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g' /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/arch
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/arch && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -O2 -w -fPIC  -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/arch -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o arch.o /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/config.tests/arch/arch.cpp
> c++ -Wl,-O1 -o arch arch.o   -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link   /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a
Detected architecture: x86_64 (mmx sse sse2)
test config.qtbase.tests.architecture gave result x86_64
Checking for SSE2 instructions... 
...
Skipped 802 lines
...
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/libjpeg && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -g -fPIC -g -w -fPIC  -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o main.o main.cpp
> c++  -o libjpeg main.o   -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib -ljpeg   /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a
 => source accepted.
test config.qtbase_gui.libraries.libjpeg succeeded
Checking for libpng... 
Trying source 0 (type pkgConfig) of library libpng ...
+ /bin/pkg-config --exists --silence-errors libpng
+ /bin/pkg-config --modversion libpng
> 1.6.40
+ /bin/pkg-config --libs-only-L libpng
> -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib
+ /bin/pkg-config --libs-only-l libpng
> -lpng16d -lm -lz
+ /bin/pkg-config --cflags libpng
> -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include/libpng16 -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/libpng && /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/bin/qmake "CONFIG -= qt debug_and_release app_bundle lib_bundle" "CONFIG += static warn_off console single_arch" 'QMAKE_LIBDIR += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link' 'INCLUDEPATH += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g' 'QMAKE_USE += libpng' 'QMAKE_LIBS_LIBPNG = -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib -lpng16d -lm -lz' 'QMAKE_INCDIR_LIBPNG = /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include/libpng16 /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include' 'QMAKE_DEPENDS_LIBPNG_CC = ZLIB' 'QMAKE_DEPENDS_LIBPNG_LD = ZLIB' 'QMAKE_LIBS_ZLIB = /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/libpng
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/libpng && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -g -fPIC -g -w -fPIC  -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/libpng16 -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o main.o main.cpp
> c++  -o libpng main.o   -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib -lpng16d -lm -lz /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a   /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a
 => source accepted.
test config.qtbase_gui.libraries.libpng succeeded
Checking for libmd4c... 
Trying source 0 (type pkgConfig) of library libmd4c ...
+ /bin/pkg-config --exists --silence-errors md4c
pkg-config did not find package.
  => source produced no result.
Trying source 1 (type inline) of library libmd4c ...
md4c.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_gui.libraries.libmd4c FAILED
Checking for tslib... 
Trying source 0 (type inline) of library tslib ...
tslib.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_gui.libraries.tslib FAILED
Checking for xkbcommon >= 0.5.0... 
Trying source 0 (type pkgConfig) of library xkbcommon ...
+ /bin/pkg-config --exists --silence-errors xkbcommon '>=' 0.5.0
pkg-config did not find package.
  => source produced no result.
Trying source 1 (type inline) of library xkbcommon ...
xkbcommon/xkbcommon.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_gui.libraries.xkbcommon FAILED
Checking for CUPS... 
Trying source 0 (type inline) of library cups ...
cups/cups.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_printsupport.libraries.cups FAILED
Checking for DB2 (IBM)... 
Trying source 0 (type inline) of library db2 ...
  => source failed condition 'config.win32'.
Trying source 1 (type inline) of library db2 ...
sqlcli.h not found in [] and global paths.
sqlcli1.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_sqldrivers.libraries.db2 FAILED
Checking for InterBase... 
Trying source 0 (type inline) of library ibase ...
  => source failed condition 'config.win32'.
Trying source 1 (type inline) of library ibase ...
ibase.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_sqldrivers.libraries.ibase FAILED
Checking for OCI (Oracle)... 
Trying source 0 (type inline) of library oci ...
  => source failed condition 'config.win32'.
Trying source 1 (type inline) of library oci ...
oci.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_sqldrivers.libraries.oci FAILED
Checking for ODBC... 
Trying source 0 (type inline) of library odbc ...
  => source failed condition 'config.win32'.
Trying source 1 (type inline) of library odbc ...
  => source failed condition 'config.darwin'.
Trying source 2 (type inline) of library odbc ...
sql.h not found in [] and global paths.
sqlext.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_sqldrivers.libraries.odbc FAILED
Checking for SQLite (version 2)... 
Trying source 0 (type inline) of library sqlite2 ...
sqlite.h not found in [] and global paths.
  => source produced no result.
test config.qtbase_sqldrivers.libraries.sqlite2 FAILED
Checking for TDS (Sybase)... 
Trying source 0 (type sybaseEnv) of library tds ...
  => source failed condition 'config.win32'.
Trying source 1 (type sybaseEnv) of library tds ...
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/tds && /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/bin/qmake "CONFIG -= qt debug_and_release app_bundle lib_bundle" "CONFIG += static warn_off console single_arch" 'QMAKE_LIBDIR += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link' 'INCLUDEPATH += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g' 'QMAKE_USE += tds' 'QMAKE_LIBS_TDS = -lsybdb' /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/tds
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/tds && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -g -fPIC -g -w -fPIC  -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o main.o main.cpp
> main.cpp:2:10: fatal error: sybfront.h: No such file or directory
>     2 | #include <sybfront.h>
>       |          ^~~~~~~~~~~~
> compilation terminated.
> gmake: *** [Makefile:170: main.o] Error 1
 => source failed verification.
test config.qtbase_sqldrivers.libraries.tds FAILED
Checking for SQLite (version 3)... 
Trying source 0 (type pkgConfig) of library sqlite3 ...
+ /bin/pkg-config --exists --silence-errors sqlite3
+ /bin/pkg-config --modversion sqlite3
> 3.43.2
+ /bin/pkg-config --libs-only-L sqlite3
> -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib
+ /bin/pkg-config --libs-only-l sqlite3
> -lsqlite3 -ldl
+ /bin/pkg-config --cflags sqlite3
> -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/sqlite3 && /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/bin/qmake "CONFIG -= qt debug_and_release app_bundle lib_bundle" "CONFIG += static warn_off console single_arch" 'QMAKE_LIBDIR += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link' 'INCLUDEPATH += /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a 'QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' QMAKE_LIBS_PRIVATE+=/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a QMAKE_CC=cc QMAKE_CXX=c++ QMAKE_AR=ar QMAKE_RANLIB=ranlib QMAKE_STRIP=strip QMAKE_NM=nm QMAKE_RC= QMAKE_MT= QMAKE_AR+=qc QMAKE_LINK=c++ QMAKE_LINK_SHLIB=c++ QMAKE_LINK_C=cc QMAKE_LINK_C_SHLIB=cc 'QMAKE_CFLAGS_DEBUG+=-fPIC -g' 'QMAKE_CXXFLAGS_DEBUG+=-fPIC -g' 'QMAKE_USE += sqlite3' 'QMAKE_LIBS_SQLITE3 = -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib -lsqlite3 -ldl' 'QMAKE_INCDIR_SQLITE3 = /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../../include' 'QMAKE_DEPENDS_SQLITE3_CC = ZLIB' 'QMAKE_DEPENDS_SQLITE3_LD = ZLIB' 'QMAKE_LIBS_ZLIB = /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a' /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/sqlite3
+ cd /home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/x64-linux-dbg/config.tests/sqlite3 && MAKEFLAGS= /usr/bin/gmake
> c++ -c -pipe -g -fPIC -g -w -fPIC  -I. -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include/qt5 -I/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/include -I/home/lekmax_77/PROJECT/Babel/_deps/vcpkg-src/buildtrees/qt5-base/src/5.15.11-13623e1e19.clean/mkspecs/linux-g++ -o main.o main.cpp
> c++  -o sqlite3 main.o   -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/manual-link -L/home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/pkgconfig/../../lib -lsqlite3 -ldl /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a   /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libbz2d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libpng16d.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libz.a /home/lekmax_77/PROJECT/Babel/vcpkg_installed/x64-linux/debug/lib/libzstd.a
 => source accepted.
test config.qtbase_sqldrivers.libraries.sqlite3 succeeded
Done running configuration tests.

Configure summary:

Build type: linux-g++ (x86_64, CPU features: mmx sse sse2)
Compiler: gcc 11.4.0
Configuration: sse2 aesni sse3 ssse3 sse4_1 sse4_2 avx avx2 avx512f avx512bw avx512cd avx512dq avx512er avx512ifma avx512pf avx512vbmi avx512vl compile_examples enable_new_dtags f16c largefile optimize_debug precompile_header rdrnd rdseed shani x86SimdAlways debug c++11 c++14 c++17 c++1z concurrent dbus reduce_exports reduce_relocations release_tools static stl
Build options:
  Mode ................................... debug; optimized tools
  Optimize debug build ................... yes
  Building shared libraries .............. no
  Using C standard ....................... C11
  Using C++ standard ..................... C++17
  Using ccache ........................... no
  Using new DTAGS ........................ yes
  Generating GDB index ................... no
  Relocatable ............................ no
  Using precompiled headers .............. yes
  Using LTCG ............................. no
  Target compiler supports:
    SSE .................................. SSE2 SSE3 SSSE3 SSE4.1 SSE4.2
    AVX .................................. AVX AVX2
    AVX512 ............................... F ER CD PF DQ BW VL IFMA VBMI
    Other x86 ............................ AES F16C RDRAND SHA
    Intrinsics without -mXXX option ...... yes
  Build parts ............................ libs tools
Qt modules and options:
  Qt Concurrent .......................... yes
  Qt D-Bus ............................... yes
  Qt D-Bus directly linked to libdbus .... no
  Qt Gui ................................. yes
  Qt Network ............................. yes
  Qt Sql ................................. yes
  Qt Testlib ............................. yes
  Qt Widgets ............................. yes
  Qt Xml ................................. yes
Support enabled for:
  Using pkg-config ....................... yes
  udev ................................... yes
  Using system zlib ...................... yes
  Zstandard support ...................... yes
Qt Core:
  DoubleConversion ....................... yes
    Using system DoubleConversion ........ yes
  GLib ................................... no
  iconv .................................. yes
  ICU .................................... no
  Built-in copy of the MIME database ..... yes
  Tracing backend ........................ <none>
  Logging backends:
    journald ............................. no
    syslog ............................... no
    slog2 ................................ no
  PCRE2 .................................. yes
    Using system PCRE2 ................... yes
Qt Network:
  getifaddrs() ........................... yes
  IPv6 ifname ............................ yes
  libproxy ............................... no
  Linux AF_NETLINK ....................... yes
  OpenSSL ................................ yes
    Qt directly linked to OpenSSL ........ yes
  OpenSSL 1.1 ............................ yes
  DTLS ................................... yes
  OCSP-stapling .......................... yes
  SCTP ................................... no
  Use system proxies ..................... yes
  GSSAPI ................................. no
Qt Gui:
  Accessibility .......................... yes
  FreeType ............................... yes
    Using system FreeType ................ yes
  HarfBuzz ............................... yes
    Using system HarfBuzz ................ yes
  Fontconfig ............................. yes
  Image formats:
    GIF .................................. yes
    ICO .................................. yes
    JPEG ................................. yes
      Using system libjpeg ............... yes
    PNG .................................. yes
      Using system libpng ................ yes
  Text formats:
    HtmlParser ........................... yes
    CssParser ............................ yes
    OdfWriter ............................ yes
    MarkdownReader ....................... yes
      Using system libmd4c ............... no
    MarkdownWriter ....................... yes
  EGL .................................... yes
  OpenVG ................................. no
  OpenGL:
    Desktop OpenGL ....................... yes
    OpenGL ES 2.0 ........................ no
    OpenGL ES 3.0 ........................ no
    OpenGL ES 3.1 ........................ no
    OpenGL ES 3.2 ........................ no
  Vulkan ................................. no
  Session Management ..................... yes
Features used by QPA backends:
  evdev .................................. yes
  libinput ............................... no
  INTEGRITY HID .......................... no
  mtdev .................................. no
  tslib .................................. no
  xkbcommon .............................. no
  X11 specific:
    XLib ................................. yes
    XCB Xlib ............................. no
    EGL on X11 ........................... yes
    xkbcommon-x11 ........................ no
QPA backends:
  DirectFB ............................... no
  EGLFS .................................. yes
  EGLFS details:
    EGLFS OpenWFD ........................ no
    EGLFS i.Mx6 .......................... no
    EGLFS i.Mx6 Wayland .................. no
    EGLFS RCAR ........................... no
    EGLFS EGLDevice ...................... yes
    EGLFS GBM ............................ no
    EGLFS VSP2 ........................... no
    EGLFS Mali ........................... no
    EGLFS Raspberry Pi ................... no
    EGLFS X11 ............................ no
  LinuxFB ................................ yes
  VNC .................................... yes
Qt Sql:
  SQL item models ........................ yes
Qt Widgets:
  GTK+ ................................... no
  Styles ................................. Fusion Windows
Qt PrintSupport:
  CUPS ................................... no
Qt Sql Drivers:
  DB2 (IBM) .............................. no
  InterBase .............................. no
  MySql .................................. no
  OCI (Oracle) ........................... no
  ODBC ................................... no
  PostgreSQL ............................. no
  SQLite2 ................................ no
  SQLite ................................. yes
    Using system provided SQLite ......... yes
  TDS (Sybase) ........................... no
Qt Testlib:
  Tester for item models ................. yes

Note: Using static linking will disable the use of dynamically
loaded plugins. Make sure to import all needed static plugins,
or compile needed modules into the library.

ERROR: Feature 'xcb' was enabled, but the pre-condition 'features.thread && libs.xcb && tests.xcb_syslibs && features.xkbcommon-x11' failed.

ERROR: Feature 'xcb-xlib' was enabled, but the pre-condition 'features.xlib && libs.xcb_xlib' failed.
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "qt5",
    "asio"
  ]
}

```
</details>
