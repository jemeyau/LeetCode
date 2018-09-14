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
        int iNums1Size = nums1.size();
        int iNums2Size = nums2.size();

        if (0 == iNums1Size)
        {
            return type_own(nums2);
        }

        if (0 == iNums2Size)
        {
            return type_own(nums1);
        }

        int iNums1MinNum = nums1[0];
        int iNums1MaxNum = nums1[iNums1Size - 1];

        int iNums2MinNum = nums2[0];
        int iNums2MaxNum = nums2[iNums2Size - 1];

        /*
        nums1:     |3,4,5|
        nums2:            |6,7,8|
        */
        if (iNums1MaxNum < iNums2MinNum)
        {
            return type_jump(nums1, nums2);
        }
        /*
        nums1:      |3,4,5|
        nums2: |1,2|
        */
        else if (iNums2MaxNum < iNums1MinNum)
        {
            return type_jump(nums2, nums1);
        }
        /*
        nums1:          |3,4,5|
        nums2:      |1,2,3,4,5|
        */
        else if (iNums1MaxNum <= iNums2MaxNum && iNums1MinNum >= iNums2MinNum)
        {
            return type_own(nums2);
        }
        /*
        nums1:          |2,3,4,5,6|
        nums2:            |3,4,5|
        */
        else if (iNums2MaxNum <= iNums1MaxNum && iNums2MinNum >= iNums1MinNum)
        {
            return type_own(nums1);
        }
        /*
        nums1:     |3,4,5|
        nums2:         |5,6,7|
        */
        else if (iNums1MaxNum >= iNums2MinNum && iNums1MaxNum < iNums2MaxNum && iNums1MinNum < iNums2MinNum)
        {
            return type_cross(nums1, nums2);
        }
        /*
       nums1:        |3,4,5|
       nums2       |2,3,4|
       */
        else if (iNums1MaxNum > iNums2MaxNum && iNums2MinNum > iNums2MinNum && iNums1MinNum <= iNums2MaxNum)
        {
            return type_cross(nums2, nums1);
        }

        cout << "should not be here!" << endl;
        return 0;
    }

  private:
    int binary_find(vector<int> vec, int key)
    {
        size_t mid, left = 0;
        size_t right = vec.size(); // one position passed the right end
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (key > vec[mid])
            {
                left = mid + 1;
            }
            else if (key < vec[mid])
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
    /*
    交叉型
    a:  [1,2,3,4]
    b:      [3,6,7]
    */
    double type_cross(vector<int> &left, vector<int> &right)
    {
        //cout << "type cross" << endl;
        int iLeftSize = left.size();
        int iRightSize = right.size();

        //int iLeftMax = left[iLeftSize - 1];
        int iRightMin = right[0];

        int iSameLen = iLeftSize - binary_find(left, iRightMin);
        if (0 >= iSameLen)
        {
            return 0;
        }

        int iTotalLen = iLeftSize + iRightSize - iSameLen;
        int iMidIndex = iTotalLen / 2;

        if (iTotalLen % 2)
        {
            if (iMidIndex < iLeftSize)
            {
                return left[iMidIndex];
            }

            return right[iMidIndex - iLeftSize - iSameLen];
        }

        if (iMidIndex == iLeftSize)
        {
            return (left[iLeftSize - 1] + (double)right[iSameLen]) / 2;
        }
        else if (iMidIndex < iLeftSize)
        {
            return (left[iMidIndex] + (double)left[iMidIndex - 1]) / 2;
        }
        else
        {
            return (right[iMidIndex - iLeftSize + iSameLen] + (double)right[iMidIndex - iLeftSize - 1 + iSameLen]) / 2;
        }
    }

    /*
    跨越型
    a:  [1,2,3,4,5]
    b:                [7,8,9,10]
    */
    double type_jump(vector<int> &left, vector<int> &right)
    {
        //cout << "type jump" << endl;
        int iLeftSize = left.size();
        int iRightSize = right.size();

        int iMidIndex = (iLeftSize + iRightSize) / 2;

        if ((iLeftSize + iRightSize) % 2)
        {
            if (iMidIndex < iLeftSize)
            {
                return left[iMidIndex];
            }

            return right[iMidIndex - iLeftSize];
        }

        if (iMidIndex == iLeftSize)
        {
            return (left[iLeftSize - 1] + (double)right[0]) / 2;
        }
        else if (iMidIndex < iLeftSize)
        {
            return (left[iMidIndex] + (double)left[iMidIndex - 1]) / 2;
        }
        else
        {
            return (right[iMidIndex - iLeftSize] + (double)right[iMidIndex - 1 - iLeftSize]) / 2;
        }
    }

    /*
   包含型
   a:  [1,2,4,5]
   b     [2,3]
   */
    double type_own(vector<int> &bigger)
    {
        //cout << "type own" << endl;
        int iBiggerSize = bigger.size();
        int iMidIndex = iBiggerSize / 2;

        if (iBiggerSize % 2)
        {
            return bigger[iMidIndex];
        }

        return (bigger[iMidIndex] + (double)bigger[iMidIndex - 1]) / 2;
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