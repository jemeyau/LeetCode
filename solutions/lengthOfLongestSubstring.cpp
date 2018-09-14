/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 


Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
wrong answer: "ggububgvfk"
*/

#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int iStrLen = s.length();
        if (iStrLen <= 1)
        {
            return iStrLen;
        }

        int iBeginIndex = 0;
        int iEndIndex = 1;

        int iMaxLength = 0;
        int iCurLength = 0;

        /*
        直观的从前往后扫描
        */
        while (iEndIndex < iStrLen)
        {
            char chNextChar = s[iEndIndex];

            for (int i = iBeginIndex; i < iEndIndex; i++)
            {
                if (chNextChar == s[i])
                {
                    //如果第i个字符与next字符重复，则下个substring的开始位置直接设为i+1
                    iBeginIndex = i + 1;
                    break;
                }
            }

            iEndIndex++;

            iCurLength = iEndIndex - iBeginIndex;
            if (iMaxLength < iCurLength)
            {
                iMaxLength = iCurLength;
            }
        }

        return iMaxLength;
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

        cout << "string: " << s << endl;

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}