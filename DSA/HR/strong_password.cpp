#include <iostream>
#include <string>
#include <unordered_set>
#include <deque>

int minimumNumber_1(int n, std::string password)
{
    // Requirement flags
    bool hasUpper = false, hasLower = false, hasSpecial = false, hasDigit = false;

    // Set of special characters
    std::unordered_set<char> specialChars = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

    // Check each character for requirements
    for (char c : password)
    {
        if (isdigit(c))
            hasDigit = true;
        else if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (specialChars.count(c))
            hasSpecial = true;

        if (hasDigit && hasUpper && hasLower && hasSpecial)
            break; // All requirements met
    }

    // Calculate missing requirements
    int missingTypes = (!hasDigit) + (!hasUpper) + (!hasLower) + (!hasSpecial);

    // Ensure minimum length of 6
    return std::max(missingTypes, 6 - n);
}

int minimumNumber_2(int n, std::string password)
{
    // Return the minimum number of characters to make the password strong
    int size = password.size();
    bool hasUpper = false;
    bool hasLower = false;
    bool hasSpecial = false;
    bool hasDigit = false;

    std::unordered_set<char> specialChars = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    std::deque<int> locked_indexes{};

    for (int i{}; i < size; i++)
    {
        char c = password[i];

        if (!hasDigit && isdigit(c))
        {
            locked_indexes.push_back(i);
            hasDigit = true;
        }
        else if ((!hasUpper || !hasLower) && isalpha(c))
        {
            if (!hasUpper && isupper(c))
            {
                locked_indexes.push_back(i);
                hasUpper = true;
            }
            else if (!hasLower && islower(c))
            {
                locked_indexes.push_back(i);
                hasLower = true;
            }
        }
        else if (!hasSpecial && specialChars.find(c) != specialChars.end())
        {
            locked_indexes.push_back(i);
            hasSpecial = true;
        }

        if (hasDigit && hasLower && hasUpper && hasSpecial)
            break;
    }

    auto changePassword = [&](char new_char, int index)
    {
        if (password.size() < 6)
        {
            password.push_back(new_char);
        }
        else
        {
            password[index] = new_char;
        }
    };

    int index = 0;
    int changes = 0;
    while (!hasDigit || !hasLower || !hasUpper || !hasSpecial || password.size() < 6)
    {
        if (
            (!locked_indexes.empty() && index != locked_indexes[0]) ||
            locked_indexes.empty())
        {
            changes++;
            if (!hasDigit)
            {
                changePassword('1', index);
                hasDigit = true;
            }
            else if (!hasLower)
            {
                changePassword('a', index);
                hasLower = true;
            }
            else if (!hasUpper)
            {
                changePassword('A', index);
                hasUpper = true;
            }
            else if (!hasSpecial)
            {
                changePassword('!', index);
                hasSpecial = true;
            }
            else
            {
                password.push_back('a');
            }
        }

        if (!locked_indexes.empty() && locked_indexes[0] >= index)
        {
            locked_indexes.pop_front();
        }
        index++;
    }

    return changes;
}
