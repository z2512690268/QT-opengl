"D:\QT\Qt5.14.2\5.14.2\android\bin\androiddeployqt.exe" --verbose --output android-build --no-build --input android-opengles-deployment-settings.json --gradle --reinstall --device 8GH0220410021608

"F:\Android\Android\Sdk\platform-tools\adb.exe" -s 8GH0220410021608 pull /system/bin/app_process app_process
"F:\Android\Android\Sdk\platform-tools\adb.exe" -s 8GH0220410021608 pull /system/bin/app_process32 app_process
"F:\Android\Android\Sdk\platform-tools\adb.exe" -s 8GH0220410021608 pull /system/bin/linker linker
"F:\Android\Android\Sdk\platform-tools\adb.exe" -s 8GH0220410021608 pull /system/lib/libc.so libc.so