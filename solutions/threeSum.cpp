/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include "comm_header.h"

#include <map>

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;

        if (nums.size() < 3)
            return ret;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int want = 0 - nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum == want)
                {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};

                    ret.push_back(tmp);

                    while (left < right && nums[right] == tmp[2])
                        right--;
                    while(left < right && nums[left] == tmp[1])
                        left++;

                    //cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
                }
                else if (sum > want)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }

            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }

        return ret;
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

        vector<vector<int>> ret = Solution().threeSum(nums);
    }
    return 0;
}