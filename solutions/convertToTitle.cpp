#include "comm_header.h"

class Solution
{
public:
    string convertToTitle(int n)
    {
        char a = 'A';
        string ret;

        do
        {
            int x = n % 26;
            //cout << string(1, (a + left - 1)) << endl;
            ret = string(1, (a + (x + 25) % 26)) + ret;
            if (n <= 26)
                break;

            n /= 26;
            if (0 == x)
                n -= 1;
        } while (n > 0);

        return ret;
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

        string ret = Solution().convertToTitle(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}