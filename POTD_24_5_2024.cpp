// POTD geeksforgeeks 24/05/2024
// Partitions with Given Difference

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        const int MOD = 1e9 + 7;
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if ((d + sum) % 2 != 0)
            return 0;

        int target_sum = (d + sum) / 2;
        if (target_sum < 0)
            return 0;

        vector<int> dp(target_sum + 1, 0);
        dp[0] = 1;

        for (int num : arr)
        {
            for (int j = target_sum; j >= num; --j)
            {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }

        return dp[target_sum];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
