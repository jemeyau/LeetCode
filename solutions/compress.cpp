#include "comm_header.h"

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        size_t len = chars.size();

        int cursor = 0;
        int write = 0;
        for (int read = 0; read < len; read++)
        {
            if (read + 1 != len && chars[read + 1] == chars[cursor])
                continue;

            chars[write++] = chars[cursor];
            int count = read - cursor + 1;
            cursor = read + 1;
            if (count <= 1)
                continue;

            stringstream ss;
            ss << count;
            string str;
            ss >> str;
            for (int i = 0; i < str.size(); i++)
            {
                chars[write++] = str[i];
            }
        }

        return write;
    }
};

int main()
{
    return 0;
}