@Composable
fun MyCompose() {
    SelectionContainer {
        Column(modifier = Modifier.padding(30.dp))
        {
            Text(text = "Hello World")
            DisableSelection {
                Text(text = "Hello World")
            }
            Text(text = "Hello World")
        }
    }
}

// ---

@Composable
fun MyCompose() {
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp)
            .border(
                width = 1.dp,
                color = MaterialTheme.colorScheme.onBackground,
                shape = RoundedCornerShape(15.dp)
            )
    )
    {
        Text(
            text = "A Simple Text",
            modifier = Modifier
                .padding(16.dp)
                .border(
                    width = 1.dp,
                    color = MaterialTheme.colorScheme.onBackground,
                    shape = RoundedCornerShape(15.dp)
                )
                .background(MaterialTheme.colorScheme.primary, shape = RoundedCornerShape(15.dp))
                .padding(16.dp),
            color = MaterialTheme.colorScheme.onPrimary,
        )


        val textColor = MaterialTheme.colorScheme.primary
        Text(
            buildAnnotatedString {
                withStyle(style = ParagraphStyle(textAlign = TextAlign.Center)) {
                    append("Hello ")
                    withStyle(
                        style = SpanStyle(
                            color = textColor,
                            fontSize = 30.sp,
                            fontWeight = FontWeight.Bold
                        )
                    ) {
                        append("World")
                    }
                }
            }, modifier = Modifier.width(200.dp)
        )


        Text(text = "Hello, Android!".repeat(20), maxLines = 2, overflow = TextOverflow.Ellipsis, modifier = Modifier.padding(16.dp))
    }
}