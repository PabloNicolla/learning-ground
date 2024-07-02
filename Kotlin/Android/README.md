# Android

## Upgrade Kotlin 2.0.0

```kotlin
// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
// alias(libs.plugins.jetbrains.kotlin.android) apply false                 # remove
// id("org.jetbrains.kotlin.android") version "2.0.0" apply false           # add
// id("org.jetbrains.kotlin.plugin.compose") version "2.0.0" apply false    # add
}
```

```kotlin
plugins {
// alias(libs.plugins.jetbrains.kotlin.android)     # remove
// id("org.jetbrains.kotlin.android")               # add
// id("org.jetbrains.kotlin.plugin.compose")        # add
}
```

## Use KSP

```kotlin
// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
    id("com.google.devtools.ksp") version "2.0.0-1.0.22" apply false
}
```

```kotlin
plugins {
    id("com.google.devtools.ksp")
}

android { // Remove the following:
//    buildFeatures {
//        compose = true
//    }
//    composeOptions {
//        kotlinCompilerExtensionVersion = "1.5.1"
//    }
}
```