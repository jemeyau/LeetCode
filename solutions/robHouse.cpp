#include "comm_header.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        size_t size = nums.size();
        if (0 == size)
            return 0;
        if (1 == size)
            return nums[0];
        int money1 = nums[0] + realRob(nums, 2);
        int money2 = nums[1] + realRob(nums, 3);

        return money1 > money2 ? money1 : money2;
    }

    int realRob(vector<int>& nums, size_t beg)
    {
        size_t size = nums.size();

        if (beg >= size)
            return 0;

        if (beg + 1 == size)
            return nums[beg];

        int money1 = nums[beg] + realRob(nums, beg + 2);
        int money2 = nums[beg + 1] + realRob(nums, beg + 3);

        return money1 > money2 ? money1 : money2;
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

        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}