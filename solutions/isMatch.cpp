/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

#include "comm_header.h"

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        //cout << "s:" << s << " p:" << p << endl;
        //1. find the first fix lenght substr of p
        int pos = -1;
        int len = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (i + 1 < p.size() && p[i + 1] == '*')
            {
                i++;
                if (1 <= len)
                {
                    break;
                }
                continue;
            }
            else
            {
                if (-1 == pos)
                {
                    pos = i;
                    len++;
                }
                else
                {
                    len++;
                }
            }
        }

        if (0 == len)
        {
            //    cout << "len 0" << endl;
            int j = 0;
            for (int i = 0; i < p.size(); i++)
            {
                for (; j < s.size(); j++)
                {
                    if (p[i] != s[j] && p[i] != '.')
                    {
                        i++;
                        break;
                    }
                }
            }

            if (j != s.size())
                return false;

            //    cout << "match" << endl;
            return true;
        }

        ///cout << "fix: " << p.substr(pos, len) << endl;

        if (s.size() < len)
        {
            return false;
        }

        //2. get the match position of substr in s
        for (int index = 0; index < s.size(); index++)
        {
            int j = 0;
            //be careful of j + pos < p.size() and j+index < s.size()
            for (; j < len && j + pos < p.size() && j + index < s.size(); j++)
            {
                if (p[j + pos] != s[index + j] && '.' != p[j + pos])
                    break;
            }

            if (j == len)
            {
                bool bLeftMatch = isMatch(s.substr(0, index), p.substr(0, pos));
                bool bRightMatch = isMatch(s.substr(index + len, string::npos), p.substr(pos + len, string::npos));

                if (bLeftMatch && bRightMatch)
                    return true;
            }
            else
            {
                //cout << "not find" << endl;
            }
        }

        //3. recursion
        return false;
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}