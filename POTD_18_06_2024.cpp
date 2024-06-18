// POTD geeksforgeeks 18/06/2024
// Number of Rectangles in a Circle

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
    int rectanglesInCircle(int r)
    {
        int count = 0;
        int limit = 2 * r;
        for (int a = 1; a <= limit; ++a)
        {
            for (int b = 1; b <= limit; ++b)
            {
                if (a * a + b * b <= 4 * r * r)
                {
                    count++;
                }
            }
        }
        return count;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
