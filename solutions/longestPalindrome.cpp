/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include "comm_header.h"

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int beg = 0;
        int end = s.size() - 1;

        for (int i = s.size(); i > 0; i--)
        {
            int ret = doLongest(s, i);
            if (ret >= 0)
                return s.substr(ret, i);
        }
        return "";
    }

  private:
    bool isPalindromic(string &s, int beg, int end)
    {
        int len = end - beg + 1;

        if (1 == len)
            return true;
        if (2 == len || 3 == len)
            return s[beg] == s[end];

        int i = 0;
        int j = 0;

        if (len % 2)
        {
            i = beg + len / 2 - 1;
            j = beg + len / 2 + 1;
        }
        else
        {
            i = beg + len / 2 - 1;
            j = beg + len / 2;
        }

        while (i >= beg && j <= end)
        {
            if (s[i] != s[j])
                return false;
            i--;
            j++;
        }

        return true;
    }

    int doLongest(string &s, int len)
    {
        int s_len = s.size();
        for (int i = 0; i + len <= s_len; i++)
        {
            if (isPalindromic(s, i, i + len - 1))
                return i;
        }

        return -1;
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

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}