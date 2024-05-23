#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
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