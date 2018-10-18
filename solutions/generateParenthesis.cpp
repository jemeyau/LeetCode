/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include "comm_header.h"

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        if (0 == n)
            return ret;

        generate(ret, "", 0, 0, n);

        return ret;
    }

  private:
    void generate(vector<string> &ret, string cur, int open, int close, int max)
    {
        if (cur.size() == max * 2)
            ret.push_back(cur);

        if (open < max)
            generate(ret, cur + '(', open + 1, close, max);
        if (close < open)
            generate(ret, cur + ')', open, close + 1, max);
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int num = stringToInteger(line);

        vector<string> ret = Solution().generateParenthesis(num);

        for (int i = 0; i < ret.size(); i++)
            cout << ret[i] << endl;
    }
    return 0;
}