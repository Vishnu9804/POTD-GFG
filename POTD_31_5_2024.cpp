#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swapNibbles(int n)
    {
        int leftNibble = (n & 0xF0) >> 4;
        int rightNibble = (n & 0x0F) << 4;
        return (rightNibble | leftNibble);
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
