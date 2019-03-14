#include "comm_header.h"

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int size_a = a.size();
        int size_b = b.size();
        if (0 == size_a)
            return b;
        if (0 == size_b)
            return a;

        int max_size = size_a > size_b ? size_a + 1 : size_b + 1;

        int upper = 0;
        while (size_a || size_b)
        {
            int sum = 0;
            if (size_a)
                sum += a[size_a - 1] - '0';

            if (size_b)
                sum += b[size_b - 1] - '0';

            sum += upper;

            upper = sum / 2;
            sum = sum % 2;

/*
            cout << "a:" << a[size_a - 1] << 
            " b:" << b[size_b - 1] <<
            " sum:" << sum <<
            " upper:" << upper << endl;
            */

            if (size_a)
            {
                a[size_a - 1] = sum + '0';
                size_a--;
            }
            else
            {
                string str_sum(1, sum + '0');
                a = str_sum + a;
            }

            if (size_b)
                size_b--;

            //cout << "a:" << a << endl;
        }

        if (upper)
        {
            //cout << "upper:" << upper << endl;
            string str_upper(1, upper + '0');
            a = str_upper + a;
        }

        return a;
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}