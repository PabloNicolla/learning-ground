#include <vector>
#include <iostream>

using namespace std;

void miniMaxSum(vector<int> arr)
{
    long long int min{arr[0]}, max{arr[0]}, total{arr[0]};

    for (int i{1}; i < arr.size(); ++i)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
        total += arr[i];
    }

    std::cout << total - max << " " << total - min << "\n";
}