#include <vector>
#include <climits>

/*
brute: put in a vector all and sort then find median
tc O( (n+m).log(n+m) ) sc: O(n+m)

better: merge two sorted arrays using two pointer approach and the find median
tc O( (n+m)) sc: O(n+m)

optimal: Binary search
tc :O(log(n+m))
*/

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;

        std::vector<int> &A = nums1;
        std::vector<int> &B = nums2;

        if (B.size() < A.size())
        {
            std::swap(B, A);
        }

        int A_left = 0;
        int A_right = A.size() - 1;
        while (A_left <= A_right)
        {
            int a_index = (A_right - A_left) / 2 + A_left;
            int b_index = half - a_index;

            int Aleft = a_index > 0 ? A[a_index - 1] : INT_MIN;
            int Aright = a_index < A.size() ? A[a_index] : INT_MAX;
            int Bleft = b_index > 0 ? B[b_index - 1] : INT_MIN;
            int Bright = b_index < B.size() ? B[b_index] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total % 2 != 0)
                {
                    return std::max(Aleft, Bleft);
                }
                return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
            }
            else if (Aleft > Bright)
            {
                A_right = a_index - 1;
            }
            else
            {
                A_left = a_index + 1;
            }
        }
        return -1;
    }
};