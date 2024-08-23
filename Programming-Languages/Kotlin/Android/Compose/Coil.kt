/* AndroidManifest.xml

<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
...
    <uses-permission android:name="android.permission.INTERNET" />
...
    <application
        android:allowBackup="true"
...
*/

/* build.gradle.kts
...
Dependencies {
...
    implementation(libs.coil.compose)
...
}
*/

@Composable
fun MyCompose() {
    Box(
        modifier = Modifier
            .width(150.dp)
            .height(150.dp)
    ) {
        var loading by remember { mutableStateOf(true) }
        AsyncImage(
            model = ImageRequest.Builder(LocalContext.current)
                .data("https://cataas.com/cat?type=square")
                .crossfade(true)
                .build(),
//            placeholder = painterResource(R.drawable.ic_google_logo),
            contentDescription = stringResource(R.string.cat_image),
            contentScale = ContentScale.Crop,
            modifier = Modifier.clip(CircleShape),
            onSuccess = { loading = false }
        )
        if (loading) {
            CircularProgressIndicator()
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    AppTheme {
        MyCompose()
    }
}