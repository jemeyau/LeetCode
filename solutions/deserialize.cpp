#include "comm_header.h"


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    /*
    ex:"[[11,[222,333]],1,[44,55],2,3]"
    */
    NestedInteger deserialize(string s) {
        NestedInteger ret;
        if (s.empty())
            return ret;
        if (s[0] != '[')
        {
            ret.setInteger(stoi(s));
            return ret;
        }

        // empty list like "[]"
        if (s.size() <= 2)
        {
            return ret;
        }

        size_t pos = 1;
        int level = 0;
        for (int i = 1; i < s.size(); i++)
        {
            /*
            level euqals zero means we get a full list
                s[i] == ',' means we get a single integer
                i == s.size() - 1 means we reach the last element
            */
            if ((level == 0) &&
                ((s[i] == ',') || (i == s.size() - 1)))
            {
                ret.add(deserialize(s.substr(pos, i - pos)));
                pos = i + 1;
                continue;
            }

            if (s[i] == '[')
                level++;
            else if (s[i] == ']')
                level--;
        }

        return ret;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        getline(cin, line);
        cout << out << endl;
    }
    return 0;
}