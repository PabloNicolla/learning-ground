#include <vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int size = gas.size();
        int net_gas_sum = 0;
        std::vector<int> net_gas(size);

        for (int i{}; i < size; ++i)
        {
            net_gas[i] = gas[i] - cost[i];
            net_gas_sum += gas[i] - cost[i];
        }

        if (net_gas_sum < 0)
            return -1;

        int start{};
        int curr{};
        net_gas_sum = 0;

        while (curr < size)
        {
            net_gas_sum += net_gas[curr];
            if (net_gas_sum < 0)
            {
                while (net_gas_sum < 0 && start <= curr)
                {
                    net_gas_sum -= net_gas[start];
                    ++start;
                }
                curr = start;
                continue;
            }
            ++curr;
        }
        return start;
    }
};
