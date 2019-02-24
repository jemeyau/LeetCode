#include "comm_header.h"

class Solution
{
  public:
    string countAndSay(int n)
    {
        if (0 == n)
            return "";

        if (1 == n)
            return "1";

        //Recursion, get the 'n-1' string first, then analysis.
        string subStr = countAndSay(n - 1);

        string retStr = "";

        for (int i = 0; i < subStr.size(); i++)
        {
            char cur = subStr[i];

            int beg = 1;
            while (true)
            {
                char target = char(beg + 1);
                if (target != cur) {
                    beg++;
                    continue;
                }
                
                int j = 1;
                while (i + 1 < subStr.size())
                {
                    if (subStr[i + 1] == target)
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }

                retStr.append(1, char(48 + j));
                retStr.append(1, target);
                break;
            }
        }

        return retStr;
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
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}