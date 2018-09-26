/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only
store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1].
For the purpose of this problem, assume that your function
returns 0 when the reversed integer overflows.
*/

#include "comm_header.h"

#include <limits.h>

class Solution
{
  public:
    int reverse(int x)
    {
        long int lResult = 0;
        bool bIspositive = true;
        if (x < 0)
            bIspositive = false;
        
        while (x)
        {
            lResult += x % 10;

            if (x /= 10)
            {
                lResult *= 10;
            }

            if (bIspositive && lResult >= INT_MAX)
                return 0;
            if (!bIspositive && lResult <= INT_MIN)
                return 0;
        }

        return lResult;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}