class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = dSquareSum(n);

        while (slow != fast)
        {
            fast = dSquareSum(dSquareSum(fast));
            slow = dSquareSum(slow);
        }

        return slow == 1;
    }

    int dSquareSum(int n)
    {
        int output = 0;
        while (n != 0)
        {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};
