#include <string>
#include <iostream>
using namespace std;

int marsExploration(string s)
{
    int sosCount = s.size() / 3;
    int correctCount = 0;

    for (int i{}; i < s.size(); ++i)
    {
        cout << i << " " << correctCount << "\n";
        switch (i % 3)
        {
        case 1:
            if (s[i] == 'O')
                ++correctCount;
            break;
        case 0:
        case 2:
            if (s[i] == 'S')
                ++correctCount;
            break;
        }
    }

    return s.size() - correctCount;
}