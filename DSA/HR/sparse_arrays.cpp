#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    std::vector<int> ans{};
    std::unordered_map<std::string_view, int> counter{};

    for (const std::string &str : strings)
    {
        counter[str]++;
    }

    for (const std::string &q : queries)
    {
        ans.push_back(counter[q]);
    }

    return ans;
}