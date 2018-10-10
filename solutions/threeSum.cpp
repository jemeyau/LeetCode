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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp;
            int i_want = 0 - nums[i];
            tmp.push_back(nums[i]);
            for (int j = i + 1; j < nums.size(); j++)
            {
                int j_want = i_want - nums[j];
                tmp.push_back(nums[j]);
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[k] == j_want)
                    {
                        tmp.push_back(nums[k]);
                        bool exist = false;
                        for (int m = 0; m < ret.size(); m++)
                        {
                            vector<int>& a_ret = ret[m];

                            if (a_ret[0] == nums[i] && a_ret[1] == nums[j] && a_ret[2] == nums[k])
                            {
                                exist = true;
                                break;
                            }
                        }
                        if (!exist)
                            ret.push_back(tmp);
                        tmp.pop_back();
                        break;
                    }
                }
                tmp.pop_back();
            }
            tmp.pop_back();
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