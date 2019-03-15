#include "comm_header.h"

class Solution
{
  public:
    int climbStairs(int n)
    {
        if (2 >= n)
            return n;

        int i = 3;
        int dp_i_1 = 2;
        int dp_i_2 = 1;
        int dp_i = 0;
        while (i <= n)
        {
            dp_i = dp_i_1 + dp_i_2;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;

            i++;
        }

        return dp_i;
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
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}