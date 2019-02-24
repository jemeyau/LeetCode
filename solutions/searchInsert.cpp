#include "comm_header.h"

class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (0 == nums.size())
        {
            return 0;
        }

        if (target < nums[0])
        {
            return 0;
        }

        if (target > nums[nums.size() - 1])
        {
            return nums.size();
        }

        //binary search
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;

        while (low <= high)
        {
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                break;
            }

            if (low > high)
            {
                break;
            }

            mid = (low + high) / 2;
        }

        if (nums[mid] < target)
        {
            mid++;
        }

        return mid;
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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}