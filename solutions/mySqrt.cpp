#include "comm_header.h"

class Solution
{
  public:
    int mySqrt(int x)
    {
        if (1 >= x)
            return x;

        /*
        if x >= 4^n, then 2^n <= sqrt(x) <= x / (2^n)
        */

        int low = 1;
        int high = x;

        int64_t n = 1;
        int index = 0;
        while (true)
        {
            n *= 4;
            if (x < n)
                break;
            index++;
            low *= 2;
            high /= 2;
        }

        cout << "low: " << low << " high:" << high << endl;

        while (low <= high)
        {
            int mid_mid = low * low;

            //in case of overflow
            if (INT_MAX - 2*low -2 == mid_mid)
                return low + 1;
            if (INT_MAX - 2*low - 2 < mid_mid)
                return low;
            int mid_1_mid = (low + 1) * (low + 1);
            if (mid_mid <= x && mid_1_mid > x)
                return low;

            low++;
        }

        return low;
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