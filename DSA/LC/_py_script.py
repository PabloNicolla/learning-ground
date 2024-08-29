import pyperclip
import re

# Function to convert the string


def convert_string(input_string, file_format):
    # Extract the number and the title
    match = re.match(r'(\d+)\.\s+(.+)', input_string)
    if not match:
        raise ValueError("Input string format is incorrect.")

    number = match.group(1)
    title = match.group(2)

    # Convert the title to lowercase and replace spaces with underscores
    formatted_title = title.lower().replace(' ', '_')

    # Combine the number, formatted title, and file format
    result = f"{number}_{formatted_title}.{file_format}"

    # Copy to clipboard
    pyperclip.copy(result)

    return result


# Prompt the user for input
input_string = input("Enter the string (e.g., '1046. Last Stone Weight'): ")
file_format = input("Enter the file format (e.g., 'cpp', 'py', 'java'): ")

# Convert and copy to clipboard
try:
    output = convert_string(input_string, file_format)
    print(f"Converted and copied to clipboard: {output}")
except ValueError as e:
    print(e)
