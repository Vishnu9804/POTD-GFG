// POTD geeksforgeeks 20/05/2024
// Integral Points Inside Triangle

#include <bits/stdc++.h>

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

using namespace std;

class Solution
{
public:
    long long int InternalCount(long long int p[], long long int q[], long long int r[])
    {

        long long int area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));
        auto boundaryPoints = [](long long int x1, long long int y1, long long int x2, long long int y2)
        {
            return __gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
        };

        long long int b1 = boundaryPoints(p[0], p[1], q[0], q[1]);
        long long int b2 = boundaryPoints(q[0], q[1], r[0], r[1]);
        long long int b3 = boundaryPoints(r[0], r[1], p[0], p[1]);

        long long int B = b1 + b2 + b3 - 3;

        long long int I = (area - B + 2) / 2;

        return I;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
