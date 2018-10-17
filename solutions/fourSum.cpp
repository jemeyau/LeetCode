/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include "comm_header.h"

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        if (nums.size() < 4)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++)
        {
            vector<int> tmp(nums.begin() + i + 1, nums.end());

            threeSum(tmp, target - nums[i], ret, nums[i]);

            while (i + 1 < nums.size() - 3 && nums[i + 1] == nums[i])
                i++;
        }

        return ret;
    }

  private:
    void threeSum(vector<int> &nums, int target, vector<vector<int>> &ret, int cur)
    {
        if (nums.size() < 3)
            return;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int want = target - nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum == want)
                {
                    vector<int> tmp = {cur, nums[i], nums[left], nums[right]};

                    ret.push_back(tmp);

                    while (left < right && nums[right] == tmp[3])
                        right--;
                    while (left < right && nums[left] == tmp[2])
                        left++;

                    cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << " " << tmp[3] << endl;
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

int stringToInteger(string input)
{
    return stoi(input);
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
        getline(cin, line);
        int target = stringToInteger(line);

        vector<vector<int>> ret = Solution().fourSum(nums, target);
    }
    return 0;
}