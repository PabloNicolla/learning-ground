#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **letterCombinations(char *digits, int *returnSize)
{
    if (*digits == '\0')
    {
        *returnSize = 0;
        return NULL;
    }

    // Define the phone map for the digits
    const char *phone_map[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Set initial result array with an empty string
    char **result = (char **)malloc(sizeof(char *));
    result[0] = strdup("");
    *returnSize = 1;

    // Iterate over each digit
    for (int i = 0; digits[i] != '\0'; i++)
    {
        int digit = digits[i] - '0'; // Convert char to int
        const char *letters = phone_map[digit];
        int letterCount = strlen(letters);

        // Create a temporary result for new combinations
        char **temp_result = (char **)malloc((*returnSize) * letterCount * sizeof(char *));
        int tempSize = 0;

        // Combine each current string with new possible letters
        for (int j = 0; j < *returnSize; j++)
        {
            for (int k = 0; k < letterCount; k++)
            {
                temp_result[tempSize] = (char *)malloc(strlen(result[j]) + 2);
                strcpy(temp_result[tempSize], result[j]);
                temp_result[tempSize][strlen(result[j])] = letters[k];
                temp_result[tempSize][strlen(result[j]) + 1] = '\0';
                tempSize++;
            }
        }

        // Free the old result and update it with the new temp_result
        for (int j = 0; j < *returnSize; j++)
        {
            free(result[j]);
        }
        free(result);

        result = temp_result;
        *returnSize = tempSize;
    }

    return result;
}

int main()
{
    char digits[] = "23";
    int returnSize = 0;

    char **combinations = letterCombinations(digits, &returnSize);

    printf("Letter Combinations:\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", combinations[i]);
        free(combinations[i]); // Free each combination
    }
    free(combinations); // Free the result array

    return 0;
}
