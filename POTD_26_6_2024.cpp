#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCoverage(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int coverage = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i > 0 && matrix[i - 1][j] == 1)
                        coverage++;
                    if (i < n - 1 && matrix[i + 1][j] == 1)
                        coverage++;
                    if (j > 0 && matrix[i][j - 1] == 1)
                        coverage++;
                    if (j < m - 1 && matrix[i][j + 1] == 1)
                        coverage++;
                }
            }
        }

        return coverage;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
