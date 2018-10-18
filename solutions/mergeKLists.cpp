/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

#include "comm_header.h"

/**
 * Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode *ret = NULL;
        ListNode *dummy = NULL;
        int firstIndex = -1;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *curList = lists[i];
            if (NULL == curList)
                continue;

            if (-1 == firstIndex)
            {
                firstIndex = i;
                continue;
            }

            if (curList->val < lists[firstIndex]->val)
            {
                firstIndex = i;
            }
        }

        //be aware of empty lists
        if (-1 == firstIndex)
            return NULL;

        ret = lists[firstIndex];
        dummy = lists[firstIndex];
        lists[firstIndex] = lists[firstIndex]->next;

        do
        {
            ListNode *tmp = NULL;
            int index = -1;
            for (int i = 0; i < lists.size(); i++)
            {
                ListNode *curList = lists[i];
                if (NULL == curList)
                {
                    lists.erase(lists.begin() + i);
                    i--;
                    continue;
                }

                if (-1 == index)
                {
                    index = i;
                    continue;
                }

                if (curList->val < lists[index]->val)
                {
                    index = i;
                }
            }

            if (-1 == index)
                break;

            dummy->next = lists[index];
            dummy = dummy->next;
            lists[index] = lists[index]->next;

            if (1 == lists.size())
                break;
        } while (true);

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

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

vector<ListNode *> stringToListNodeArray(string &input)
{
    vector<ListNode *> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = '|';
    while (getline(ss, item, delim))
    {
        ListNode *l = stringToListNode(item);
        output.push_back(l);
    }

    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<ListNode *> lists = stringToListNodeArray(line);

        /*
        for (int i = 0; i < lists.size(); i++)
        {
            cout << listNodeToString(lists[i]) << endl;
        }
        */

        ListNode *ret = Solution().mergeKLists(lists);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}