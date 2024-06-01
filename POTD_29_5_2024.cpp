// POTD geeksforgeeks 29/05/2024
// Geek and its Game of Coins

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
        bool dp[n + 1];
        dp[0] = false;
        dp[1] = true;

        for (int i = 2; i <= n; i++)
        {
            if (i >= x && !dp[i - x] || i >= y && !dp[i - y] || !dp[i - 1])
                dp[i] = true;
            else
                dp[i] = false;
        }

        return dp[n];
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}
