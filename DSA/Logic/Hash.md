# Hash

## Custom Hash for Strongly Typed Languages

### Hashing Data Structure with Several Values

#### String as Key

```cpp
void main() {
    std::unordered_map<std::string, std::vector<std::string>> map;

    std::array<int, 26> arr{/*...*/};

    string key;
    for (int num : arr) {
        key += "#" + to_string(num);
    }

    map[key].push_back(s);
}
```

#### Prime Multiplication

```cpp
const int PRIME = 31; // A prime number for hashing

int computeHash(const std::vector<int>& freq) {
    int hash_value = 0;
    for (int i = 0; i < 26; ++i) {
        hash_value = hash_value * PRIME + freq[i];
    }
    return hash_value;
}

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<int, std::vector<std::string>> anagramGroups;
    for (const auto& str : strs) {
        std::vector<int> freq(26, 0);
        for (char c : str) {
            freq[c - 'a']++;
        }
        int hash_value = computeHash(freq);
        anagramGroups[hash_value].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramGroups) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    std::vector<std::string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(input);
    for (const auto& group : result) {
        for (const auto& str : group) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
```