/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

/*
rows = 5
0 x       x       x
1 x     x x     x x
2 x   x   x   x   x
3 x x     x x     x x
4 x       x       x 
  0 1 2 3 4 5 6 7 8 9
*/
#include "comm_header.h"

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (1 == numRows)
        {
            return s;
        }
        int size = s.size();

        int elements_per_cycle = 2 * numRows - 2;

        char *ret = (char *)malloc(size);
        int ret_len = 0;

        for (int row_index = 0; row_index < numRows; row_index++)
        {
            //cycle_index points to the first element of every cycle
            for (int cycle_index = 0; cycle_index + row_index < size; cycle_index += elements_per_cycle)
            {
                ret[ret_len++] = s[cycle_index + row_index];
                if ((row_index != 0) &&
                    (row_index != numRows - 1) &&
                    ((cycle_index + elements_per_cycle - row_index) < size))
                {
                    ret[ret_len++] = s[cycle_index + elements_per_cycle - row_index];
                }
            }
        }

        ret[ret_len] = '\0';

        return string(ret);
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}