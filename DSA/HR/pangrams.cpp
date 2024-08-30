#include <string>
#include <unordered_set>

using namespace std;

string pangrams(string s)
{
    std::unordered_set<char> seen{};

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            seen.insert(tolower(c));
    }

    return seen.size() == 26 ? "pangram" : "not pangram";
}