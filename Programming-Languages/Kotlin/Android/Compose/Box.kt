@Composable
fun MyCompose() {
    Box(modifier = Modifier.fillMaxSize(), contentAlignment = Alignment.TopCenter) {
        Box(
            modifier = Modifier
                .background(Color.Blue)
                .width(300.dp)
                .height(100.dp)
                .verticalScroll(rememberScrollState()),
            contentAlignment = Alignment.Center
        ) {
            Box(
                modifier = Modifier
                    .height(50.dp)
                    .width(50.dp)
                    .background(Color.Green)
            )
            Text(text = "line1\nline2\nline3\nline4\nline5\nline6", fontSize = 40.sp)
        }
    }
}