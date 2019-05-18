#include "comm_header.h"

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        if (0 == s.size())
            return true;

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            char lc = s[left];
            char rc = s[right];

            if (!isAlphabetaOrNumber(lc))
            {
                left++;
                continue;
            }

            if (!isAlphabetaOrNumber(rc))
            {
                right--;
                continue;
            }

            if (lc != rc)
            {
                //cout << "left:" << left << " " << lc << " right:" << right  << " " << rc << endl;
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

private:
    bool isAlphabetaOrNumber(char &c)
    {
        if (c >= '0' && c <= '9')
            return true;

        if (c >= 'a' && c <= 'z')
        {
            c -= 32;
            return true;
        }

        if (c >= 'A' && c <= 'Z')
            return true;

        return false;
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}