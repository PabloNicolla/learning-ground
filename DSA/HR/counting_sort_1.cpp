#include <vector>

using namespace std;

vector<int> countingSort(vector<int> arr)
{
    std::vector<int> ans(100, 0);

    for (int num : arr)
    {
        ans[num]++;
    }

    return ans;
}