#include "comm_header.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);

        return root;
    }

private:
    //key idea: get the middle element of array as the root node,
    //and [begIdx, midIdx) as the left child,
    // (midIdx, endIdx] as the right child.
    TreeNode *sortedArrayToBST(vector<int> &nums, int begIdx, int endIdx)
    {
        if (begIdx > endIdx)
            return NULL;

        if (0 == nums.size())
            return NULL;

        int midIdx = (begIdx + endIdx) / 2;

        TreeNode *root = new TreeNode(nums[midIdx]);
        //root->val = nums[midIdx];

        TreeNode *left = sortedArrayToBST(nums, begIdx, midIdx - 1);
        TreeNode *right = sortedArrayToBST(nums, midIdx + 1, endIdx);

        root->left = left;
        root->right = right;

        return root;
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

        TreeNode *ret = Solution().sortedArrayToBST(nums);
    }
    return 0;
}