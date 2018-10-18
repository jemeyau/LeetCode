/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

#include "comm_header.h"

/**
 Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

int stringToInteger(string input)
{
    return stoi(input);
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

class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1 || head == NULL)
            return head;

        ListNode *ret = NULL;
        ListNode *dummy = head;

        vector<ListNode *> vec(k, NULL);

        ListNode *last = NULL;
        int i = 0;
        while (i < k)
        {
            if (!head)
                break;
            vec[i] = head;
            head = head->next;

            i++;
            if (i != k)
            {
                continue;
            }

            //cout << "size: " << vec.size() << endl;

            //do k elements reverse
            for (int j = 0; j < k; j++)
            {
                if (0 == j)
                    vec[j]->next = vec[k - 1]->next;
                else
                    vec[j]->next = vec[j - 1];
            }

            //cout << vec[0]->val << " " << vec[1]->val << endl;

            if (!last)
                last = vec[0];
            else
            {
                last->next = vec.back();
                last = vec[0];
            }

            if (!ret)
                ret = vec.back();

            i = 0;
        }

        // be aware of that list size is smaller than k
        if (!ret)
            return dummy;

        return ret;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode *ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}