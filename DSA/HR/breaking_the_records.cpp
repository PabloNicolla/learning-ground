#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores)
{
    int min{scores[0]}, max{scores[0]};
    int minCount{}, maxCount{};

    for (int score : scores)
    {
        if (score < min)
        {
            minCount++;
            min = score;
        }
        else if (score > max)
        {
            maxCount++;
            max = score;
        }
    }

    return {maxCount, minCount};
}