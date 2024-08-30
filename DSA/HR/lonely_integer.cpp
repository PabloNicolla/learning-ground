#include <vector>
#include <map>

using namespace std;

int lonelyinteger(vector<int> a)
{
    std::map<int, int> m;

    for (int num : a)
    {
        m[num]++;
    }

    for (const auto &[k, v] : m)
    {
        if (v == 1)
        {
            return k;
        }
    }
    return -1;
}
