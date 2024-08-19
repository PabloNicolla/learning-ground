#include <stdio.h>
#include <string.h>

int characterReplacement(char *s, int k)
{
  int count[26] = {0};
  int maxCount = 0;
  int maxLen = 0;
  int left = 0;

  for (int right = 0; s[right] != '\0'; ++right)
  {
    maxCount = (maxCount > ++count[s[right] - 'A']) ? maxCount : count[s[right] - 'A'];

    while ((right - left + 1) - maxCount > k)
    {
      count[s[left] - 'A']--;
      left++;
    }

    maxLen = (maxLen > (right - left + 1)) ? maxLen : (right - left + 1);
  }

  return maxLen;
}