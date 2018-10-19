/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

#include "comm_header.h"

/*
key idea:
dividend: 10, divisor: 3

10 - 3 << 0 = 7
10 - 3 << 1 = 4 **
10 - 3 << 2 = -2
4 >= 3, so continue

4 - 3 << 0 = 1 **
4 - 3 << 1 = -2
1 < 3, so quit

ret = 1 << 1 + 1 << 0
*/

class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        int64_t a = dividend;
        int64_t b = divisor;
        if (abs(a) < abs(b))
            return 0;

        bool positive = false;
        if ((a < 0 && b < 0) || (a > 0 && b > 0))
            positive = true;

        a = abs(a);
        b = abs(b);

        int scale = 0;
        int sub_val = 0;

        int64_t ret = 0UL;

        do
        {
            sub_val = a - (b << scale);
            if (sub_val <= 0)
                break;
            scale++;
        } while (true);

        if (0 == sub_val)
        {
            ret = 1UL << scale;
        }
        else
        {
            scale--;
            sub_val = a - (b << scale);

            if (sub_val >= b)
                ret = (1UL << scale) + divide(sub_val, b);
            else
                ret = 1UL << scale;
        }

        if (!positive)
            ret = 0 - ret;

        if (ret > INT_MAX || ret < INT_MIN)
            return INT_MAX;
        return ret;
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
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}