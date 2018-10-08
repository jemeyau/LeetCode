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
        int minLen = minRequireLen(p);
        if (s.size() < minLen)
        {
            return false;
        }

        const int maxAddChars = s.size() - minLen;

        /*
        bool bRet = formatRegStr(p);
        //cout << "p: " << p << endl;
        if (!bRet)
            return false;
*/

        //cout << "sSize: " << s.size() << "maxAdd: " << maxAddChars << endl;

        int sIndex = 0;
        int lastMatchChars = 0;

        for (int iIndex = 0; iIndex < p.size(); iIndex++)
        {
            //should do match until not match
            bool bUntil = false;

            char preCh = p[iIndex];

            if (iIndex + 1 < p.size() && p[iIndex + 1] == '*')
                bUntil = true;

            if (bUntil)
            {
                for (; sIndex < s.size(); sIndex++)
                {
                    char sCh = s[sIndex];

                    if (sCh != preCh && preCh != '.')
                    {
                        break;
                    }

                    if (lastMatchChars < maxAddChars)
                    {
                        lastMatchChars++;
                    }
                    else
                    {
                        break;
                    }
                }

                iIndex++;
            }
            else
            {
                char sCh = s[sIndex];

                if ('.' == preCh || preCh == sCh)
                {
                    lastMatchChars = 0;
                    sIndex++;
                    continue;
                }
                else
                {
                    bool bMatch = false;
                    while (lastMatchChars > 0)
                    {
                        lastMatchChars--;
                        sCh = s[--sIndex];
                        if ('.' == preCh || preCh == sCh)
                        {
                            sIndex++;
                            bMatch = true;
                            break;
                        }
                    }

                    if (!bMatch)
                    {
                        //cout << "s: " << s.substr(sIndex) << ", p: " << p.substr(iIndex) << endl;
                        return false;
                    }
                }
            }
        }

        if (sIndex >= s.size())
        {
            return true;
        }

        //cout << "s: " << s.substr(sIndex) << endl;
        return false;
    }

  private:
    /*
    if p looks like "ab*bcd",
    format p to "ab*cd"
    */
    bool formatRegStr(string &p)
    {
        if ('*' == p[0])
        {
            return false;
        }

        for (int i = 1; i < p.size(); i++)
        {
            char c = p[i];

            if ('*' != c)
                continue;

            while (i + 1 < p.size())
            {
                if (p[i + 1] == p[i - 1])
                    p.erase(i + 1, 1);
                else
                    break;
            }
        }

        return true;
    }

    int minRequireLen(string &p)
    {
        int len = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (i + 1 < p.size() && p[i + 1] == '*')
                i++;
            else
                len++;
        }

        return len;
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