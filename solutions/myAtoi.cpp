/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters
as necessary until the first non-whitespace character is found.
Then, starting from this character, takes an optional initial
plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.

The string can contain additional characters after those that
form the integral number, which are ignored and have no effect
on the behavior of this function.

If the first sequence of non-whitespace characters in str is not
a valid integral number, or if no such sequence exists because
either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [−231,  231 − 1].
If the numerical value is out of the range of representable values,
INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
#include "comm_header.h"

#include <climits>

class Solution
{
  public:
    int myAtoi(string str)
    {
        int iStrSize = str.size();
        if (0 == iStrSize)
            return 0;

        int iResult = 0;
        int iTmpValue = 0;

        //if already started or not
        bool bState = false;

        bool bPositive = true;

        for (int iIndex = 0; iIndex < iStrSize; iIndex++)
        {
            char chCharacter = str[iIndex];

            if (bState)
            {
                //something like "   122abc"
                if (chCharacter > '9' || chCharacter < '0')
                {
                    return iResult;
                }
            }
            else
            {
                if (' ' == chCharacter)
                {
                    continue;
                }
                else if ('+' == chCharacter)
                {
                    bPositive = true;
                    bState = true;
                    continue;
                }
                else if ('-' == chCharacter)
                {
                    bPositive = false;
                    bState = true;
                    continue;
                }
                else if ('0' <= chCharacter && '9' >= chCharacter)
                {
                    bPositive = true;
                    bState = true;
                }
                //something like " abc123 "
                else
                {
                    return 0;
                }
            }

            int iNum = (int)(chCharacter - 48);
            iTmpValue = iTmpValue * 10 + iNum;

            if (bPositive)
            {
                if (iResult != iTmpValue / 10)
                    return INT_MAX;
                else
                    iResult = iTmpValue;
            }
            else
            {
                if (iResult != iTmpValue / 10)
                    return INT_MIN;
                else
                    iResult = -1 * iTmpValue;
            }
        }

        return iResult;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}