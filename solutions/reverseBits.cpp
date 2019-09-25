#include "comm_header.h"

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int left = 31;
        int right = 0;

        while (left > right)
        {
            uint32_t left_val = (((uint32_t)1) << left) & n;
            uint32_t right_val = (((uint32_t)1) << right) & n;

            //cout << left_val << " " << right_val << " " << left << " " << right << endl;

            if (left_val)
            {
                n |= (((uint32_t)1) << right);
                //cout << "a " << (((uint32_t)1) << right) << " " << n << endl;
            }
            else
            {
                n &= ~(((uint32_t)1) << right);
                //cout << "b" << endl;
            }

            if (right_val)
                n |= (((uint32_t)1) << left);
            else
                n &= ~(((uint32_t)1) << left);

            right++;
            left--;
        }

        return n;
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

        int ret = Solution().reverseBits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}