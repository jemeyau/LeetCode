/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pstResult = NULL;
        ListNode* pstResultIter = NULL;
        ListNode* pstTmpResult = NULL;
        ListNode* pstL1Iter = l1;
        ListNode* pstL2Iter = l2;

        //是否产生进位
        int iUp = 0;

        int iL1Val = 0;
        int iL2Val = 0;

        int iSum = 0;
        int iLeft = 0;

        while (NULL != pstL1Iter && NULL != pstL2Iter)
        {
            iL1Val = pstL1Iter->val;
            iL2Val = pstL2Iter->val;

            iSum = iUp + iL1Val + iL2Val;

            iUp = iSum / 10;
            iLeft = iSum % 10;

            pstTmpResult = new ListNode(iLeft);

            if (NULL == pstResult)
            {
                pstResult = pstTmpResult;
                pstResultIter = pstResult;
            }
            else
            {
                pstResultIter->next = pstTmpResult;
                pstResultIter = pstTmpResult;
            }

            pstL1Iter = pstL1Iter->next;
            pstL2Iter = pstL2Iter->next;

/*
            cout << "L1Val:" << iL1Val
                << " L2Val:" << iL2Val
                << " Sum:" << iSum
                << " Left:" << iLeft
                << " Up:" << iUp
                << endl;
                */
        }

        if (NULL != pstL1Iter && NULL != pstL2Iter)
        {
            //cout << "Should not be here." << endl;
            return NULL;
        }

        ListNode* pstLeftIter = NULL;

        if (NULL != pstL1Iter)
        {
            pstLeftIter = pstL1Iter;
        }
        else if (NULL != pstL2Iter)
        {
            pstLeftIter = pstL2Iter;
        }

        //如果无进位，则直接把较长的列表连过来
        if (0 == iUp)
        {
            pstResultIter->next = pstLeftIter;

            return pstResult;
        }

        //否则一直加到无进位产生
        while (iUp && pstLeftIter)
        {
            iSum = iUp + pstLeftIter->val;

            iUp = iSum / 10;
            iLeft = iSum % 10;

            pstTmpResult = new ListNode(iLeft);

            if (NULL == pstResult)
            {
                pstResult = pstTmpResult;
                pstResultIter = pstResult;
            }
            else
            {
                pstResultIter->next = pstTmpResult;
                pstResultIter = pstTmpResult;
            }

            pstLeftIter = pstLeftIter->next;
        }

        if (0 == iUp)
        {
            pstResultIter->next = pstLeftIter;
        }
        else
        {
            pstTmpResult = new ListNode(iUp);

            if (NULL == pstResult)
            {
                pstResult = pstTmpResult;
                pstResultIter = pstResult;
            }
            else
            {
                pstResultIter->next = pstTmpResult;
                pstResultIter = pstTmpResult;
            }
        }

        return pstResult;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}