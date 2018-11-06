/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:
Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []


wrong cases:

"wordgoodgoodgoodbestword"
["word","good","best","word"]

"wordgoodgoodgoodbestword"
["word","good","best","good"]


*/

#include "comm_header.h"

#include <set>

class Solution
{
  public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        /*
        cout << s << endl;
        for (int i = 0; i < words.size(); i++)
            cout << words[i] << endl;
        */
        map<char, vector<int>> wordsFirstCh2Index;
        for (int i = 0; i < words.size(); i++)
        {
            char firstCh = words[i][0];
            wordsFirstCh2Index[firstCh].push_back(i);
        }

        map<int, int> matchedIndex;

        for (int i = 0; i < s.size(); i++)
        {
            if (wordsFirstCh2Index.find(s[i]) == wordsFirstCh2Index.end())
                continue;

            vector<int> tmpIndex = wordsFirstCh2Index[s[i]];
            for (int j = 0; j < tmpIndex.size(); j++)
            {
                string tmpWord = words[tmpIndex[j]];
                int k = 0;
                for (; k < tmpWord.size(); k++)
                {
                    if (tmpWord[k] != s[i + k])
                        break;
                }

                if (k == tmpWord.size())
                    matchedIndex[i] = tmpIndex[j];
            }
        }

        vector<int> ret;

        set<int> alreadyIn;

        for (map<int, int>::iterator iter = matchedIndex.begin(); iter != matchedIndex.end(); iter++)
        {
            alreadyIn.clear();

            int tmpTarget = iter->first;
            int i = 0;
            for (; i < words.size(); i++)
            {
                if (matchedIndex.find(tmpTarget) == matchedIndex.end())
                    break;

                int curIndex = matchedIndex.find(tmpTarget)->second;

                if (alreadyIn.find(curIndex) != alreadyIn.end())
                {
                    //cout << "alreadyIN: " << curIndex << endl;
                    break;
                }

                alreadyIn.insert(curIndex);

                tmpTarget += words[curIndex].size();
            }

            if (i == words.size())
                ret.push_back(iter->first);
        }

        sort(ret.begin(), ret.end());

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

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<string> stringToStringVector(string input)
{
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stringToString(item));
    }

    return output;
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        getline(cin, line);
        vector<string> words = stringToStringVector(line);

        vector<int> ret = Solution().findSubstring(s, words);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}