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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
            return ret;

        vector<vector<int>> leftRet = levelOrderBottom(root->left);
        vector<vector<int>> rightRet = levelOrderBottom(root->right);

        //merge left and right result
        vector<vector<int>>::reverse_iterator leftIter = leftRet.rbegin();
        vector<vector<int>>::reverse_iterator rightIter = rightRet.rbegin();
        while(leftIter != leftRet.rend() || rightIter != rightRet.rend())
        {
            vector<int> tmp;
            if (leftIter != leftRet.rend())
            {
                for (int i = 0; i < leftIter->size(); i++)
                {
                    tmp.push_back(leftIter->at(i));
                }
                leftIter++;
            }

            if (rightIter != rightRet.rend())
            {
                for (int i = 0; i < rightIter->size(); i++)
                {
                    tmp.push_back(rightIter->at(i));
                }
                rightIter++;
            }

            ret.push_back(tmp);
        }

        //need reverse
        vector<vector<int>> realRet(ret.rbegin(), ret.rend());

        vector<int> rootRet;
        rootRet.push_back(root->val);

        realRet.push_back(rootRet);

        return realRet;
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

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);

        vector<vector<int>> ret = Solution().levelOrderBottom(root);
    }
    return 0;
}