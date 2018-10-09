/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/

#include "comm_header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;

        int minLen = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            if (minLen == -1 || minLen >= strs[i].size())
                minLen = strs[i].size();
        }

        for (int i = 0; i < minLen; i++)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (ch != strs[j][i])
                    return ret;
            }

            ret.push_back(ch);
        }

        return ret;
    }
};

int main()
{
    return 0;
}

