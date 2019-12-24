#include "comm_header.h"

class Solution
{
public:
    int countSegments(string s)
    {
        if (0 == s.size())
            return 0;

        int ret = 0;
        bool count = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (' ' != s[i] && count)
            {
                ret++;
                count = false;
                continue;
            }

            if (' ' == s[i])
            {
                count = true;
            }
        }

        return ret;
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

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().countSegments(s);

        cout << ret << endl;
    }
    return 0;
}