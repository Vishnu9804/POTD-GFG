#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
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