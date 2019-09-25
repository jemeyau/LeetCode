#include "comm_header.h"

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        while (n)
        {
            if (n & (uint32_t)1)
                ret++;
            n = n >> 1;
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
        int n = stringToInteger(line);

        int ret = Solution().hammingWeight(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}