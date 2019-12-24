#include "comm_header.h"

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int len1 = num1.size();
        int len2 = num2.size();

        if (0 == len1)
            return num2;
        if (0 == len2)
            return num1;

        char *ret = NULL;
        int len = 0;
        if (len1 > len2)
        {
            ret = new char[len1 + 1];
            len = len1 + 1;
        }
        else
        {
            ret = new char[len2 + 1];
            len = len2 + 1;
        }

        int carry = 0;
        for (int i = 1; i <= len1 || i <= len2; i++)
        {
            int val1 = 0;
            int val2 = 0;
            if (i <= len1)
                val1 = num1[len1 - i] - '0';
            if (i <= len2)
                val2 = num2[len2 - i] - '0';

            int sum = val1 + val2 + carry;
            ret[len - i] = sum % 10 + '0';
            carry = sum / 10;

            cout << "sum:" << sum << ", carry:" << carry << ", ret:" << ret[len - i] << endl;
        }

        if (carry == 0)
            return string(ret + 1, len - 1);

        ret[0] = carry + '0';

        return string(ret, len);
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}