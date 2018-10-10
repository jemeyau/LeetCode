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
    struct node
    {
        int first;
        int second;
    };

  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        map<int, vector<node>> store;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                node tmp_node;
                tmp_node.first = i;
                tmp_node.second = j;

                int sum = nums[i] + nums[j];

                store[sum].push_back(tmp_node);
            }
        }

        vector<vector<int>> ret;

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp;
            int want = 0 - nums[i];
            tmp.push_back(nums[i]);

            if (store.find(want) == store.end())
                continue;

            vector<node>& node_list = store.find(want)->second;

            for (int j = 0; j < node_list.size(); j++)
            {
                tmp.clear();
                node& one_node = node_list[j];
                if (one_node.first == i || one_node.second == i)
                    break;

                cout << "a: " << nums[i] << " " << nums[one_node.first] << " " << nums[one_node.second] << endl;

                tmp.push_back(nums[i]);
                tmp.push_back(nums[one_node.first]);
                tmp.push_back(nums[one_node.second]);

                cout << "c: " << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;

                sort(tmp.begin(), tmp.end());

                bool exist = false;
                for (int m = 0; m < ret.size(); m++)
                {
                    vector<int> &a_ret = ret[m];

                    if (a_ret[0] == tmp[0] && a_ret[1] == tmp[1] && a_ret[2] == tmp[2])
                    {
                        exist = true;
                        break;
                    }
                }
                if (!exist)
                {
                    ret.push_back(tmp);
                    cout << "b: " << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
                }
            }
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