#include <string>

using namespace std;

int countingValleys(int steps, string path)
{
    bool possibleValley{false};
    int valleyCount{};
    int height{};

    for (char c : path)
    {
        if (c == 'D')
        {
            if (height == 0)
                possibleValley = true;
            height--;
        }
        else
        {
            height++;
            if (height == 0 && possibleValley)
            {
                valleyCount++;
                possibleValley = false;
            }
        }
    }

    return valleyCount;
}