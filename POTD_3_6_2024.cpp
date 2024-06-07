// POTD geeksforgeeks 03/06/2024
// Trail of ones

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long power(long long a, long long b, long long mod)
    {
        long long ans = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                ans *= a;
                ans %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return ans;
    }
    int numberOfConsecutiveOnes(int n)
    {

        int a[n], b[n];
        a[0] = b[0] = 1;
        long long mod = 1e9 + 7;

        for (int i = 1; i < n; i++)
        {
            a[i] = (a[i - 1] + b[i - 1]) % mod;
            b[i] = a[i - 1];
        }

        return (power(2, n, mod) + mod - (a[n - 1] + b[n - 1]) % mod) % mod;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}
