@ExperimentalMaterial3Api
@Composable
fun GoogleButton(
    text: String = "Sign up with Google",
    loadingText: String = "Creating Account...",
    icon: Painter = painterResource(id = R.drawable.ic_google_logo),
    shape: Shape = RoundedCornerShape(5.dp),
    borderColor: Color = Color.LightGray,
    backgroundColor: Color = MaterialTheme.colorScheme.surface,
    progressIndicatorColor: Color = MaterialTheme.colorScheme.primary,
    onClicked: () -> Unit
) {
    var clicked by remember { mutableStateOf(false) }

    Surface(
        onClick = { clicked = !clicked },
        shape = shape,
        border = BorderStroke(width = 1.dp, color = borderColor),
        color = backgroundColor
    ) {
        Row(
            modifier = Modifier
                .padding(
                    start = 16.dp,
                    end = 24.dp,

                    )
                .height(40.dp)
                .animateContentSize(
                    animationSpec = tween(
                        durationMillis = 300,
                        easing = LinearOutSlowInEasing
                    )
                ),
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.Center
        ) {
            Icon(
                painter = icon,
                contentDescription = "Google Button",
                tint = Color.Unspecified
            )

            Spacer(modifier = Modifier.width(8.dp))

            Text(text = if (!clicked) text else loadingText)

            if (clicked) {
                Spacer(modifier = Modifier.width(16.dp))
                CircularProgressIndicator(
                    modifier = Modifier
                        .height(16.dp)
                        .width(16.dp),
                    strokeWidth = 2.dp,
                    color = progressIndicatorColor
                )
                onClicked()
            }
        }
    }

}

@ExperimentalMaterial3Api
@Composable
@Preview
fun GoogleButtonPreview() {
    GoogleButton(onClicked = {Log.d("Google Button", "Clicked")})
}