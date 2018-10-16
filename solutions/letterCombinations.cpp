/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include "comm_header.h"

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        if (digits.size() < 1)
            return ret;

        map<int, string> dig2letters;
        dig2letters[2] = "abc";
        dig2letters[3] = "def";
        dig2letters[4] = "ghi";
        dig2letters[5] = "jkl";
        dig2letters[6] = "mno";
        dig2letters[7] = "pqrs";
        dig2letters[8] = "tuv";
        dig2letters[9] = "wxyz";

        vector<string> include;

        for (int i = 0; i < digits.size(); i++)
        {
            char c = digits[i];
            int val = (int)c - 48;
            if (val < 2 || val > 9)
                return ret;

            include.push_back(dig2letters[val]);
        }

        vector<int> index(include.size());
        for (int i = 0; i < index.size(); i++)
            index[i] = 0;

        bool exit = false;
        while (!exit)
        {
            string s;
            for (int j = 0; j < index.size(); j++)
            {
                s.push_back(include[j][index[j]]);
            }

            ret.push_back(s);

            cout << s << endl;

            //level of loop
            int level = include.size();
            while (level > 0)
            {
                if (index[level - 1] + 1 < include[level - 1].size())
                {
                    index[level - 1] += 1;
                    break;
                }

                index[level - 1] = 0;
                level--;
            }

            if (level == 0)
                exit = true;
        }

        return ret;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        vector<string> ret = Solution().letterCombinations(s);
    }
    return 0;
}