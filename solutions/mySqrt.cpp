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
        long mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        //return high, not mid
        return high;
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