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

class Solution {
public:
    string longestPalindrome(string s) {
        int beg = 0;
        int end = s.size() - 1;
        
        int cur_beg = 0;
        int cur_end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int r = ((i-beg+1)<(end-i+1))?(i-beg+1):(end-i+1);
            
            int a = i;
            int b = i+1;
            bool a_b = true;
            
            int c = i-1;
            int d = i+1;
            bool c_d = true; 
            int j = 0;
            for (j = 0; j < r; j++)
            {
                if (s[a] == s[b])
                {
                    if ((cur_end - cur_beg) <= (b - a))
                    {
                        cur_end = b;
                        cur_beg = a;
                    }
                    a--;
                    b++;
                }
                else
                {
                    a_b = false;
                }
                
                if (c>=0 && s[c] == s[d])
                {
                    if ((cur_end - cur_beg) <= (d - c))
                    {
                        cur_end = d;
                        cur_beg = c;
                    }
                    c--;
                    d++;
                }
                else
                {
                    c_d = false;
                }
                
                if (!a_b && !c_d)
                {
                    break;
                }
            }
        }
        
        return s.substr(cur_beg, cur_end-cur_beg+1);
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