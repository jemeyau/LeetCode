#include "comm_header.h"

class Solution
{
  public:
    int mySqrt(int x)
    {
        if (1 >= x)
            return x;
        int low = 0;
        int high = x;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;

            int mid_mid = mid * mid;
            int mid_1_mid = (mid + 1) * (mid + 1);

            //mid_1_mid should bigger not bigger_equal than x
            if (mid_mid <= x && mid_1_mid > x)
                return mid;

            if (mid_mid > x)
                high = mid;
            else
                low = mid;
        }

        return mid;
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

        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}