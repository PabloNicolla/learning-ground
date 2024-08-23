@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    AppTheme {
        Column(
            modifier = Modifier
                .height(500.dp)
                .width(500.dp)
                .background(Color.LightGray),
            horizontalAlignment = Alignment.CenterHorizontally
        ) {
            Surface(
                modifier = Modifier
                    .width(200.dp)
                    .weight(3f),
                color = MaterialTheme.colorScheme.primary
            ) { }
            Surface(
                modifier = Modifier
                    .width(200.dp)
                    .weight(1f),
                color = MaterialTheme.colorScheme.secondary
            ) { }
        }
    }
}