#include "comm_header.h"

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (0 == nums.size())
            return 0;

        int **tmpSum = new int *[nums.size()];
        for (int i = 0; i < nums.size(); i++)
            tmpSum[i] = new int[nums.size()];

        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (i == j)
                    tmpSum[i][j] = nums[j];
                else
                    tmpSum[i][j] = tmpSum[i][j - 1] + nums[j];

                if (tmpSum[i][j] > maxSum)
                    maxSum = tmpSum[i][j];
            }
        }

        return maxSum;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}