# Gradle

## Build & Clean commands

```ps1
./gradlew assembleDebug     # Builds a debug version of your app (APK).
./gradlew assembleRelease   # Builds a release version of your app (APK), usually for distribution.
./gradlew bundleDebug       # Builds a debug Android App Bundle (AAB).
./gradlew bundleRelease     # Builds a release Android App Bundle (AAB).
./gradlew installDebug      # Builds and installs the debug APK on a connected device or emulator.
./gradlew clean             # Cleans the project, removing build outputs and intermediate files.
./gradlew test              # Runs unit tests for your project.
./gradlew lint              # Performs static code analysis to identify potential issues and improve code quality.
```

## Other Useful commands

```ps1
./gradlew tasks             # Lists all available Gradle tasks for your project.
./gradlew dependencies      # Displays the dependency tree for your project.
./gradlew signingReport     # Shows the signing configuration for your app, useful for release builds.
./gradlew app:dependencies  # Shows dependencies for a specific module (replace 'app' with the module name).
adb devices                 # Lists connected Android devices and emulators.
adb logcat                  # Displays the device or emulator's log messages.
adb shell                   # Opens a shell on the connected device or emulator.
```
