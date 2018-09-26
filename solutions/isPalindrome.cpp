/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Follow up:
Coud you solve it without converting the integer to a string?
*/

/*
key idea:
    1. find the biggest 10^n(iUp) that iUp <= x
    2. div x by iUp and mod x by 10 repeatedly, then compare the result, they should be equal;
    3. determain when to exit the loop
*/

#include "comm_header.h"

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (0 > x)
        {
            return false;
        }

        if (10 > x)
        {
            return true;
        }

        int iUp = 1;

        //find the upper to div x
        int iTmp = x / 10;
        while (iTmp)
        {
            iUp *= 10;
            iTmp /= 10;
        }

        //to judge when to end, important!
        int iLeft = iUp;
        int iRight = 1;

        while (iLeft >= iRight)
        {
            //cout << "x: " << x << ", iLeft: " << iLeft << ", iRight: " << iRight << endl;
            int iMod = x % 10;
            int iDiv = x / iUp;
            if (iMod != iDiv)
            {
                return false;
            }

            //adjust value of x
            x -= (iMod + iDiv * iUp);
            x /= 10;

            // iUp should div by 100
            iUp /= 100;

            iRight *= 10;
            iLeft /= 10;
        }

        return true;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
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
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}