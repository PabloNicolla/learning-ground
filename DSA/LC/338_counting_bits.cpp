#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution1
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1);
        int offset = 1;

        for (int i = 1; i <= n; i++)
        {
            if (offset * 2 == i)
            {
                offset = i;
            }
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};

class Solution2
{
public:
    vector<int> countBits(int n)
    {
        vector<int> countarr;
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int count = 0;
            while (num > 0)
            {
                count = count + (num % 2);
                num = num / 2;
            }
            countarr.push_back(count);
        }
        return countarr;
    }
};

class Solution3
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
            return {0};

        int bitCount = std::floor(std::log2(n)) + 2;
        std::vector<bool> memory(bitCount, false);
        std::vector<int> ans{};
        int count{};

        for (int i{}; i <= n; i++)
        {
            int bitIndex = 0;
            ans.push_back(count);
            if (memory[bitIndex] == true)
            {
                bool carry = true;
                while (carry)
                {
                    if (carry && memory[bitIndex])
                    {
                        memory[bitIndex] = false;
                        --count;
                    }
                    else if (carry && !memory[bitIndex])
                    {
                        memory[bitIndex] = true;
                        carry = false;
                        ++count;
                    }
                    ++bitIndex;
                }
            }
            else
            {
                memory[bitIndex] = true;
                ++count;
            }
        }
        return ans;
    }
};
