#include "comm_header.h"

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        size_t len = chars.size();
        if (len <= 1)
            return (int)len;

        int idx = 0;
        int retidx = 0;
        int cursor = idx + 1;
        int count = 1;
        int ret = 1;
        while (idx < len && cursor < len)
        {
            //same character, add the count
            if (chars[idx] == chars[cursor])
            {
                count++;
                cursor++;

                if (cursor != len)
                    continue;
                else
                {
                    stringstream ss;
                    ss << count;
                    string str;
                    ss >> str;

                    ret = ret + str.size();
                    chars[retidx++] = chars[idx];
                    for (int i = 0; i < str.size(); i++)
                    {
                        chars[retidx++] = str[i];
                    }

                    break;
                }
            }

            ret += 1;

            //different character, record the count
            if (1 == count)
            {
                chars[retidx++] = chars[idx];
                idx = cursor;
                cursor = idx + 1;
                if (cursor == len)
                    chars[retidx++] = chars[idx];
                continue;
            }

            stringstream ss;
            ss << count;
            string str;
            ss >> str;
            ret = ret + str.size();
            chars[retidx++] = chars[idx];
            for (int i = 0; i < str.size(); i++)
            {
                chars[retidx++] = str[i];
            }

            idx = cursor;
            cursor = idx + 1;
            count = 1;

            if (cursor == len)
                chars[retidx++] = chars[idx];
        }

        return ret;
    }
};

int main()
{
    return 0;
}