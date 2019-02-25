#include "comm_header.h"

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (0 == nums.size())
            return 0;

        int size = nums.size();
        //int *dp = new int[size];

        //since we only use dp[i-1], so O(1) space is possiable
        int dp_i_1 = nums[0]; // dp[i - 1]
        int dp_i = dp_i_1;//dp[i]
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp_i = (dp_i_1 > 0 ? dp_i_1 : 0) + nums[i]; 
            max = std::max(dp_i, max);
            dp_i_1 = dp_i; //update dp[i - 1]
        }

        return max;
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