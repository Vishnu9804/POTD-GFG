// POTD geeksforgeeks 14/05/2024
// Path With Minimum Effort

#include <bits/stdc++.h>

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

using namespace std;

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> minEfforts(rows, vector<int>(columns, INT_MAX));
        minEfforts[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (auto dir : directions)
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns)
                {
                    int newEffort = max(minEfforts[row][col], abs(heights[newRow][newCol] - heights[row][col]));
                    if (newEffort < minEfforts[newRow][newCol])
                    {
                        minEfforts[newRow][newCol] = newEffort;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return minEfforts[rows - 1][columns - 1];
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}
