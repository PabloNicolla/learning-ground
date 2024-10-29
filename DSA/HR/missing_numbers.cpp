std::vector<int> missingNumbers(std::vector<int> arr, std::vector<int> brr)
{
    std::unordered_map<int, int> count{};
    std::vector<int> ans{};

    for (int n : arr)
    {
        count[n]++;
    }
    for (int n : brr)
    {
        count[n]--;
    }

    for (const auto &kv : count)
    {
        if (kv.second < 0)
        {
            //  ans.insert(ans.end(), std::abs(kv.second), kv.first);
            ans.insert(ans.end(), 1, kv.first);
        }
    }

    std::sort(ans.begin(), ans.end());

    return ans;
}
