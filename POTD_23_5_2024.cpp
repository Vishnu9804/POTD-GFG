#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int length = 2; length <= n; ++length)
        {
            for (int i = 0; i <= n - length; ++i)
            {
                int j = i + length - 1;
                if (str[i] == str[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1] <= k ? 1 : 0;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        Solution ob;
        cout << ob.kPalindrome(str, n, k) << endl;
    }
    return 0;
}
