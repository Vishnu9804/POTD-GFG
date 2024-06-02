// POTD geeksforgeeks 30/05/2024
// String Subsequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}
