#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string splitCamelCase(string input, char type)
{
    string result;
    for (char c : input)
    {
        if (isupper(c))
        {
            result += " ";
            result += tolower(c);
        }
        else if (c == '(' || c == ')')
        {
            // Skip parentheses
        }
        else
        {
            result += c;
        }
    }
    // Trim leading space if exists
    if (!result.empty() && result[0] == ' ')
    {
        result = result.substr(1);
    }
    return result;
}

string combineToCamelCase(string input, char type)
{
    stringstream ss(input);
    string word, result;
    bool firstWord = true;

    while (ss >> word)
    {
        if (firstWord)
        {
            if (type == 'C')
            {
                word[0] = toupper(word[0]);
            }
            result += word;
            firstWord = false;
        }
        else
        {
            word[0] = toupper(word[0]);
            result += word;
        }
    }

    if (type == 'M')
    {
        result += "()";
    }

    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        char operation = line[0];
        char type = line[2];
        string content = line.substr(4);

        if (operation == 'S')
        {
            cout << splitCamelCase(content, type) << endl;
        }
        else if (operation == 'C')
        {
            cout << combineToCamelCase(content, type) << endl;
        }
    }
    return 0;
}