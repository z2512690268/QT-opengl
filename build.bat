"D:\QT\Qt5.14.2\5.14.2\android\bin\qmake.exe" opengles.pro -spec android-clang "CONFIG+=debug" "CONFIG+=qml_debug" ANDROID_ABIS="armeabi-v7a"

"F:\Android\Android\Sdk\ndk\21.4.7075529\prebuilt\windows-x86_64\bin\make.exe" -f Makefile qmake_all

"F:\Android\Android\Sdk\ndk\21.4.7075529\prebuilt\windows-x86_64\bin\make.exe" "INSTALL_ROOT=android-build" install

"F:\Android\Android\Sdk\ndk\21.4.7075529\prebuilt\windows-x86_64\bin\make.exe" -j12

"D:\QT\Qt5.14.2\5.14.2\android\bin\androiddeployqt.exe" --input android-opengles-deployment-settings.json --output android-build --android-platform android-33 --jdk D:/jdk8 --gradle