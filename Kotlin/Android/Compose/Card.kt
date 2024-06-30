@Composable
fun ExpandableCard(
    title: String,
    titleFontSize: TextUnit = MaterialTheme.typography.titleSmall.fontSize,
    titleTextFontWeight: FontWeight = FontWeight.Bold,
    description: String,
    descriptionFontSize: TextUnit = MaterialTheme.typography.bodySmall.fontSize,
    descriptionFontWeight: FontWeight = FontWeight.Normal,
    descriptionMaxLines: Int = 4,
    shape: RoundedCornerShape = RoundedCornerShape(5.dp),
    padding: Dp = 12.dp
) {
    var expandableState by remember { mutableStateOf(false) }
    val rotationState by animateFloatAsState(
        targetValue = if (expandableState) 180f else 0f,
        label = ""
    )

    Card(modifier = Modifier
        .fillMaxWidth()
        .animateContentSize(
            animationSpec = tween(
                durationMillis = 300,
                easing = LinearOutSlowInEasing
            )
        ),
        shape = shape,
        onClick = {
            expandableState = !expandableState
        }) {
        Column(
            modifier = Modifier
                .fillMaxWidth()
                .padding(padding)
        ) {
            Row(verticalAlignment = Alignment.CenterVertically) {
                Text(
                    text = title,
                    fontSize = titleFontSize,
                    fontWeight = titleTextFontWeight,
                    modifier = Modifier.weight(6f),
                    maxLines = 1,
                    overflow = TextOverflow.Ellipsis,
                )
                IconButton(
                    onClick = { expandableState = !expandableState },
                    modifier = Modifier
                        .alpha(DefaultAlpha)
                        .weight(1f)
                        .rotate(rotationState)
                ) {
                    Icon(
                        imageVector = Icons.Default.ArrowDropDown,
                        contentDescription = "Drop-Down Arrow"
                    )
                }
            }
            if (expandableState) {
                Text(
                    text = description,
                    fontSize = descriptionFontSize,
                    fontWeight = descriptionFontWeight,
                    maxLines = descriptionMaxLines,
                    overflow = TextOverflow.Ellipsis
                )
            }
        }
    }
}

@ExperimentalMaterial3Api
@Composable
@Preview
fun ExpandableCardPreview() {
    ExpandableCard(
        title = "My Title",
        description = "Lorem ipsum dolor sit amet, consectetur adipiscing elit," +
                "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." +
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit," +
                "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
    )
}