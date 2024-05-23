// POTD geeksforgeeks 20/05/2024
// Modular Exponentiation for large numbers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int power(long long int base, long long int exponent, long long int mod)
    {
        if (exponent == 0)
        {
            return 1;
        }
        long long int temp = power(base, exponent / 2, mod) % mod;
        long long int result = (temp * temp) % mod;
        if (exponent % 2 == 0)
        {
            return result;
        }
        else
        {
            return (result * base) % mod;
        }
    }

    long long int PowMod(long long int x, long long int n, long long int M)
    {
        return power(x, n, M);
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int x, n, m;
        cin >> x >> n >> m;
        Solution ob;
        long long int ans = ob.PowMod(x, n, m);
        cout << ans << "\n";
    }
    return 0;
}
