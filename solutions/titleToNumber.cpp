#include "comm_header.h"

class Solution
{
public:
    int titleToNumber(string s)
    {
        int sSize = (int)(s.size());
        if (0 == sSize)
        {
            return 0;
        }

        int ret = 0;
        int64_t val = 1;
        
        for (int i = sSize - 1; i >= 0; i--)
        {
            char element = s[i];
            ret += (element - 'A' + 1) * val;

            val *= 26;
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

        int ret = Solution().titleToNumber(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}