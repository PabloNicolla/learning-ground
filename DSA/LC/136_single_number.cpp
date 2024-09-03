#include <vector>
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};

/*
You can use the XOR operator to find a unique element in an array where all elements appear twice except one because of the following properties of the XOR operation:

    Identity Property: a⊕0=aa⊕0=a. XORing a number with zero leaves the number unchanged.

    Self-Cancellation: a⊕a=0a⊕a=0. XORing a number with itself results in zero.

    Commutativity and Associativity: The XOR operation is both commutative (a⊕b=b⊕aa⊕b=b⊕a) and associative ((a⊕b)⊕c=a⊕(b⊕c)(a⊕b)⊕c=a⊕(b⊕c)).

How XOR Helps in Finding the Unique Element:

    Given an array where all elements appear twice except for one, when you XOR all the elements together, the pairs of identical elements will cancel each other out, leaving only the unique element.

Step-by-Step Example:

Consider the array [2,3,5,4,5,3,4][2,3,5,4,5,3,4]:

    XOR all elements together:
    2⊕3⊕5⊕4⊕5⊕3⊕4
    2⊕3⊕5⊕4⊕5⊕3⊕4

    Rearrange the XOR operation (due to commutativity and associativity):
    (2⊕2)⊕(3⊕3)⊕(5⊕5)⊕4
    (2⊕2)⊕(3⊕3)⊕(5⊕5)⊕4

    Apply the self-cancellation property:
    0⊕0⊕0⊕4=4
    0⊕0⊕0⊕4=4

The unique element left is 4.
Conclusion:

The XOR operation effectively cancels out all the duplicate elements, leaving only the unique element. This method is efficient, with a time complexity of O(n)O(n) and a space complexity of O(1)O(1), as it only requires a single pass through the array and does not use any extra space.
*/