@Composable
fun MyCompose() {
    Column(
        modifier = Modifier.fillMaxSize()
    ) {
        var text by remember {
            mutableStateOf("")
        }

        OutlinedTextField(
            value = text,
            onValueChange = { text = it },
            placeholder = { Text(text = "Type Here...") },
            label = { Text(text = "Title") },
            maxLines = 2,
            leadingIcon = {
                IconButton(onClick = { /*TODO*/ }) {
                    Icon(
                        imageVector = Icons.Filled.Email,
                        contentDescription = "Email Icon"
                    )
                }
            },
            trailingIcon = {
                IconButton(onClick = { /*TODO*/ }) {
                    Icon(
                        imageVector = Icons.Filled.Check,
                        contentDescription = "Email Icon"
                    )
                }
            },
            keyboardOptions = KeyboardOptions(
                keyboardType = KeyboardType.Email,
                imeAction = ImeAction.Search
            ),
            keyboardActions = KeyboardActions(
                onSearch = {
                    Log.d("ImeAction", "Clicked")
                }
            )
        )
    }
}


@Preview(showBackground = true)
@Composable
fun DefaultPreview() {
    AppTheme {
        MyCompose()
    }
}