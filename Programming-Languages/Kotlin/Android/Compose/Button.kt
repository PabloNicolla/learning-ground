@Composable
fun MyCompose() {
    var count by remember { mutableStateOf(0) }
    Column(
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text(text = count.toString())
        Button(onClick = { count++ }) {
            Text(text = "Click me")
        }
    }
}

// ---

@Composable
fun MyCompose() {
    var name by remember { mutableStateOf("") }
    var names by remember { mutableStateOf(listOf<String>()) }
    Column(
        Modifier
            .padding(24.dp)
    ) {
        Row(modifier = Modifier.fillMaxWidth()) {
            OutlinedTextField(
                value = name,
                onValueChange = { name = it },
                modifier = Modifier.weight(1f)
            )

            Spacer(modifier = Modifier.width(16.dp))

            Button(
                onClick = {
                    if (name.isNotEmpty()) {
                        names = names + name
                        name = ""
                    }
                }, modifier = Modifier
                    .padding(start = 8.dp),
                shape = RoundedCornerShape(6.dp)
            ) {
                Text("Add")
            }
        }

        LazyColumn {
            items(names) {
                Text(
                    text = it, modifier = Modifier
                        .fillMaxWidth()
                        .padding(top = 24.dp)
                )
                HorizontalDivider()
            }
        }
    }
}