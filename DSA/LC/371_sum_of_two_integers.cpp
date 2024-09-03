class Solution
{
public:
    int getSum(int a, int b)
    {
        while (true)
        {
            int ans_and = a & b;
            int ans_xor = a ^ b;

            if (ans_and == 0)
            {
                return a | b;
            }

            ans_and <<= 1;
            a = ans_and;
            b = ans_xor;
        }
    }
};
