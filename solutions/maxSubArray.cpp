#include "comm_header.h"

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        //1. total sum
        //2. left total-sum
        //3. right total-sum
        //4. compare

        if (0 == nums.size())
        {
            return 0;
        }

        if (1 == nums.size())
        {
            return nums[0];
        }

        int totalValue = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalValue += nums[i];
        }

        return getMaxTotalSum(nums, totalValue, 0, nums.size() - 1);
    }

  private:
    int getMaxTotalSum(vector<int> &nums, int outerSum, int leftIndex, int rightIndex)
    {
        //cout << "outer sum:" << outerSum << " left:" << leftIndex << " right:" << rightIndex << endl;

        if (leftIndex == rightIndex)
            return nums[leftIndex];

        int leftSum = getMaxTotalSum(nums, outerSum - nums[rightIndex], leftIndex, rightIndex - 1);
        int rightSum = getMaxTotalSum(nums, outerSum - nums[leftIndex], leftIndex + 1, rightIndex);

        int maxSum = outerSum;

        if (leftSum > maxSum)
        {
            maxSum = leftSum;
        }

        if (rightSum > maxSum)
        {
            maxSum = rightSum;
        }

        //cout << "max sum:" << maxSum << " left:" << leftIndex << " right:" << rightIndex << endl;

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