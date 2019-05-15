#include "comm_header.h"

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret;
        ret.push_back(1);

        int index = 1;
        while (index <= rowIndex)
        {
            int elementNum = index + 1;
            int leftVal = 0;
            int lastLineElemNum = ret.size();
            for (int i = 0; i < elementNum; i++)
            {
                int sum = leftVal;
                if (i < lastLineElemNum)
                {
                    leftVal = ret[i];
                    ret[i] += sum;
                }
                else
                    ret.push_back(sum);
            }

            index++;
        }

        return ret;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int rowIndex = stringToInteger(line);

        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}