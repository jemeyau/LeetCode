#include "comm_header.h"

class Solution
{
public:
    int firstUniqChar(string s)
    {
        size_t s_len = s.size();
        if (0 == s_len)
            return -1;
        
        //the desc says that the string s contain only lowercase letters
        vector<int> record(26, 0);
        for (int i = 0; i < s_len; i++)
        {
            record[s[i] - 'a'] += 1;
        }

        for (int i = 0; i < s_len; i++)
        {
            if (record[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
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

        int ret = Solution().firstUniqChar(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}