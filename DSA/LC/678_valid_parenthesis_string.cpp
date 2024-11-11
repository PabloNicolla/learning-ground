#include <string>

class Solution
{
public:
    bool checkValidString(std::string s)
    {
        int left_min = 0;
        int right_max = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                left_min++;
                right_max++;
            }
            else if (c == ')')
            {
                left_min--;
                right_max--;
            }
            else if (c == '*')
            {
                left_min--;
                right_max++;
            }

            if (right_max <= -1)
            {
                return false;
            }
            if (left_min < 0)
            {
                left_min = 0;
            }
        }
        return left_min == 0;
    }
};
