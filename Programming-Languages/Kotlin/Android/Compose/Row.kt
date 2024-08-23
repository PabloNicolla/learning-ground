@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    AppTheme {
        Row (
            modifier = Modifier.fillMaxSize()
        ) {
            Surface(
                modifier = Modifier
                    .height(200.dp)
                    .weight(3f),
                color = MaterialTheme.colorScheme.primary
            ) { }
            Surface(
                modifier = Modifier
                    .height(200.dp)
                    .weight(1f),
                color = MaterialTheme.colorScheme.secondary
            ) { }
        }
    }
}