// POTD geeksforgeeks 26/05/2024
// Minimum Cost To Make Two Strings Identical

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findMinCost(string x, string y, int costX, int costY)
    {
        int m = x.length();
        int n = y.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcsLength = dp[m][n];

        int cost = (m - lcsLength) * costX + (n - lcsLength) * costY;

        return cost;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}
