/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int iNums1Len = nums1.size();
        int iNums2Len = nums2.size();
        if (iNums1Len <= iNums2Len)
        {
            return doFind(nums1, nums2);
        }

        return doFind(nums2, nums1);
    }
private:
    //保证rstA.size() <= rstB.size()
    double doFind(vector<int>& rstA, vector<int>& rstB)
    {
        if (rstA.size() > rstB.size())
        {
            return -1;
        }

        int m = rstA.size();
        int n = rstB.size();

        int iMinIndex = 0; 
        int iMaxIndex = m;

        double result = 0.0;

        int i = 0;
        int j = 0;
        while (iMinIndex <= iMaxIndex)
        {
            i = (iMinIndex + iMaxIndex) / 2;
            j = (m + n + 1) / 2 - i;

            if (((0 == i) || (n == j) || (rstA[i - 1] <= rstB[j])) &&
                ((m == i) || (0 == j) || (rstA[i] >= rstB[j - 1])))
            {
                int iLeftMax = 0;
                int iRightMin = 0;
                if (0 == i)
                {
                    iLeftMax = rstB[j - 1];
                }
                else if (0 == j)
                {
                    iLeftMax = rstA[i - 1];
                }
                else
                {
                    iLeftMax = (rstA[i - 1] > rstB[j - 1]) ? rstA[i - 1] : rstB[j - 1];
                }
                if ((m + n) % 2)
                {
                    result = iLeftMax;
                    break;
                }

                if (n == j)
                {
                    iRightMin = rstA[i];
                }
                else if (m == i)
                {
                    iRightMin = rstB[j];
                }
                else
                {
                    iRightMin = (rstA[i] < rstB[j]) ? rstA[i] : rstB[j];
                }

                result = (iLeftMax + iRightMin) / 2.0;
                break;
            }
            else if (rstB[j] < rstA[i - 1])
            {
                iMaxIndex = i - 1;
            }
            else
            {
                iMinIndex = i + 1;
            }
        }

        return result;
    }
};
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

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}