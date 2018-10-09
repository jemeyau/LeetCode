/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral,
just two one's added together. Twelve is written as,
XII, which is simply X + II. The number twenty seven
is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest
from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one
is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

/*
what a genius
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
*/

#include "comm_header.h"

class Solution
{
  public:
    string intToRoman(int num)
    {
        string ret;
        int thousand = num / 1000;
        num -= thousand * 1000;
        while (thousand > 0)
        {
            ret.push_back('M');
            thousand--;
        }

        int hundred = num / 100;
        num -= hundred * 100;
        if (9 == hundred)
        {
            ret.push_back('C');
            ret.push_back('M');
        }
        else if (4 == hundred)
        {
            ret.push_back('C');
            ret.push_back('D');
        }
        else
        {
            if (5 <= hundred)
            {
                ret.push_back('D');
                hundred -= 5;
            }

            while (hundred > 0)
            {
                ret.push_back('C');
                hundred--;
            }
        }

        int ten = num / 10;
        num -= ten * 10;
        if (9 == ten)
        {
            ret.push_back('X');
            ret.push_back('C');
        }
        else if (4 == ten)
        {
            ret.push_back('X');
            ret.push_back('L');
        }
        else
        {
            if (5 <= ten)
            {
                ret.push_back('L');
                ten -= 5;
            }

            while (ten > 0)
            {
                ret.push_back('X');
                ten--;
            }
        }

        if (9 == num)
        {
            ret.push_back('I');
            ret.push_back('X');
        }
        else if (4 == num)
        {
            ret.push_back('I');
            ret.push_back('V');
        }
        else
        {
            if (5 <= num)
            {
                ret.push_back('V');
                num -= 5;
            }

            while (num > 0)
            {
                ret.push_back('I');
                num--;
            }
        }

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
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}