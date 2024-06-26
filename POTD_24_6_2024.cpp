// POTD geeksforgeeks 24/06/2024
// Summed Matrix

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
    long long sumMatrix(long long n, long long q)
    {
        if (q < 2 || q > 2 * n)
        {
            return 0;
        }
        long long start = max(1LL, q - n);
        long long end = min(n, q - 1);
        return end - start + 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;

        cin >> n >> q;

        Solution ob;
        cout << ob.sumMatrix(n, q) << endl;
    }
    return 0;
}
