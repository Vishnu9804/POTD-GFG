// POTD geeksforgeeks 13/06/2024
// Number of Good Components

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int padovanSequence(int n)
    {
        const int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
        {
            return 1;
        }

        vector<long long> P(n + 1, 0);
        P[0] = 1;
        P[1] = 1;
        P[2] = 1;

        for (int i = 3; i <= n; ++i)
        {
            P[i] = (P[i - 2] + P[i - 3]) % MOD;
        }

        return P[n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
