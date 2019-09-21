#include "comm_header.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ret = 0;
        
        int64_t begin = 5;
        int tmp = 0;
        while ((tmp = n / begin) != 0)
        {
            ret += tmp;
            begin *= 5;
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

        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}