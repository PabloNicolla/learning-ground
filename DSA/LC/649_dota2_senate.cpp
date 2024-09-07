#include <string>
#include <queue>
class Solution1
{
public:
    std::string predictPartyVictory(std::string senate)
    {
        // dire < 0; radiant > 0; neutral == 0
        int power_balance = 0;
        int dire = 0;
        int radiant = 0;
        bool first_run = true;
        do
        {
            for (int i{}; i < senate.size(); ++i)
            {
                if (first_run)
                {
                    if (senate[i] == 'D')
                        dire++;
                    else if (senate[i] == 'R')
                        radiant++;
                }

                if (senate[i] == '_')
                    continue;
                else if (power_balance > 0 && senate[i] == 'D')
                {
                    senate[i] = '_';
                    power_balance--;
                    dire--;
                }
                else if (power_balance < 0 && senate[i] == 'R')
                {
                    senate[i] = '_';
                    power_balance++;
                    radiant--;
                }
                else if (senate[i] == 'R')
                    power_balance++;
                else if (senate[i] == 'D')
                    power_balance--;
            }
            first_run = false;
        } while (radiant != 0 && dire != 0);

        return dire == 0 ? "Radiant" : "Dire";
    }
};

class Solution2
{
public:
    std::string predictPartyVictory(std::string senate)
    {
        std::queue<int> radiant;
        std::queue<int> dire;
        for (int i = 0; i < senate.size(); i++)
        {

            if (senate[i] == 'R')
            {
                radiant.push(i);
            }
            else
            {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty())
        {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop();
            dire.pop();
            if (r < d)
            {
                radiant.push(r + senate.size());
            }
            else
            {
                dire.push(d + senate.size());
            }
        }
        if (!radiant.empty())
        {
            return "Radiant";
        }
        else
            return "Dire";
    }
};