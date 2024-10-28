#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int index = digits.size() - 1;
        digits[index]++;

        while (digits[index] == 10)
        {
            digits[index] = 0;
            if (index == 0)
            {
                digits.insert(digits.begin(), 1);
                break;
            }
            digits[index - 1]++;
            index--;
        }

        return digits;
    }
};
