/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

#include "comm_header.h"

class Solution
{
private:
    unordered_map<int, bool> visited;

    int max;

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                visited.clear();
                int sl = 1;
                while (BFS(matrix, i, j, sl))
                {
                    if (sl > max)
                        max = sl;
                    sl++;
                }
            }
        }
        return max * max;
    }

    int getLinerPos(vector<vector<char>> &matrix, int x, int y)
    {
        int row = matrix[0].size();

        return row * y + x;
    }

    bool posValid(vector<vector<char>> &matrix, int x, int y)
    {
        int col = matrix.size();
        int row = matrix[0].size();

        return (x < row && y < col);
    }

    /*
    sl: side length
    */
    bool BFS(vector<vector<char>> &matrix, int x, int y, int sl)
    {
        for (int i = 0; i < sl; i++)
        {
            for (int j = 0; j < sl; j++)
            {
                if (visited[getLinerPos(matrix, i + x, j + y)])
                    continue;
                if (!posValid(matrix, i + x, j + y))
                    return false;
                if ('0' == matrix[j + y][i + x])
                    return false;
                visited[getLinerPos(matrix, i + x, j + y)] = true;
            }
        }

        return true;
    }
};

int main()
{
    cout << "no output" << endl;
    return 0;
}