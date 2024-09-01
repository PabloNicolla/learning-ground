#include <vector>

using namespace std;

int birthday(vector<int> s, int d, int m)
{
    int slow = 0;
    int fast = 0;
    int sum = 0;
    int count = 0;

    for (; fast < m - 1; fast++)
    {
        sum += s[fast];
    }

    for (; fast < s.size(); fast++, slow++)
    {
        sum += s[fast];
        if (sum == d)
            count++;
        sum -= s[slow];
    }

    return count;
}