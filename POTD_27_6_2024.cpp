// POTD geeksforgeeks 27/06/2024
// Toeplitz matrix

#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}

bool isToeplitz(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    for (int col = 0; col < cols; ++col)
    {
        int value = mat[0][col];
        for (int i = 1; i < rows && col + i < cols; ++i)
        {
            if (mat[i][col + i] != value)
            {
                return false;
            }
        }
    }

    for (int row = 1; row < rows; ++row)
    {
        int value = mat[row][0];
        for (int i = 1; i < cols && row + i < rows; ++i)
        {
            if (mat[row + i][i] != value)
            {
                return false;
            }
        }
    }

    return true;
}
