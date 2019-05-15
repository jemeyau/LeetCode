#include "comm_header.h"

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;

        if (0 == numRows)
            return ret;

        vector<int> line;
        line.push_back(1);
        ret.push_back(line);

        for (int i = 2; i <= numRows; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < i; j++)
            {
                int leftIdx = -1;
                int rightIdx = -1;
                if (j > 0)
                    leftIdx = j - 1;
                if (leftIdx + 1 < ret[i - 2].size())
                    rightIdx = leftIdx + 1;

                int val = 0;
                if (-1 != leftIdx)
                    val += ret[i - 2][leftIdx];
                if (-1 != rightIdx)
                    val += ret[i - 2][rightIdx];

                tmp.push_back(val);
            }

            ret.push_back(tmp);
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
        int x = stringToInteger(line);

        vector<vector<int>> ret = Solution().generate(x);
    }
    return 0;
}