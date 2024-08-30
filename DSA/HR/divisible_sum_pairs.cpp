#include <vector>
#include <map>
#include <iostream>

using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar)
{
    std::map<int, int> cache{};
    int pairCount{};

    for (int num : ar)
    {
        int remainder = num % k;
        std::cout << remainder << " " << (k - remainder) % k << " " << cache.count((k - remainder) % k) << "\n";
        pairCount += cache[((k - remainder) % k)];
        cache[remainder]++;
    }

    return pairCount;
}