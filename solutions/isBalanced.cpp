#include "comm_header.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    bool isBalanced(TreeNode *root)
    {
        bool isB = true;
        depth(root, isB);

        return isB;
    }

private:
    // get the depth of subtree, then check the balance at the same time
    int depth(TreeNode *root, bool &isB)
    {
        if (!root)
            return 0;

        bool bLeft = true;
        bool bRight = true;

        int leftDepth = depth(root->left, bLeft);
        int rightDepth = depth(root->right, bRight);

        bool bSelf = check(leftDepth, rightDepth);

        if (!bSelf || !bLeft || !bRight)
        {
            isB = false;
            return 0;
        }

        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }

    bool check(int leftDepth, int rightDepth)
    {
        if (leftDepth > rightDepth)
        {
            if (leftDepth > rightDepth + 1)
                return false;

            return true;
        }
        else if (rightDepth > leftDepth)
        {
            if (rightDepth > leftDepth + 1)
                return false;
            return true;
        }

        return true;
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

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);

        bool ret = Solution().isBalanced(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}