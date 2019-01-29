/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
[1,3,2] -> [2,1,3]
*/

#include "comm_header.h"

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        if (1 >= nums.size())
            return;

        //find a index that nums[index - 1] < nums[index]
        int index = nums.size() - 1;
        while (index >= 1)
        {
            if (nums[index - 1] < nums[index])
                break;

            index--;
        }

        //if get a valid index from back to front, swap nums[index - 1] to the nums[index, end]
        //which value is just bigger than nums[index-1]
        if (1 <= index)
        {
            int i = nums.size() - 1;
            while (i >= index)
            {
                if (nums[i] > nums[index - 1])
                    break;

                i--;
            }

            int tmp = nums[i];
            nums[i] = nums[index - 1];
            nums[index - 1] = tmp;
        }

        //reverse nums between index to the end
        reverse(nums.begin() + index, nums.end());
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

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);

        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}