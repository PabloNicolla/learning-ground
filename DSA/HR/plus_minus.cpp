#include <vector>
#include <iostream>
using namespace std;

void plusMinus(vector<int> arr)
{
    int neg{}, zero{}, pos{}, count{};

    for (int num : arr)
    {
        if (num < 0)
            neg++;
        else if (num == 0)
            zero++;
        else
            pos++;
        count++;
    }

    std::cout << (double)pos / count << "\n";
    std::cout << (double)neg / count << "\n";
    std::cout << (double)zero / count << "\n";
}