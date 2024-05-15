// POTD geeksforgeeks 12/05/2024
// Minimum steps to destination

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
    int minSteps(int d)
    {
        int target = abs(d), s = 0, step = 0;
        while (s < target || (s - target) % 2 != 0)
        {
            step++;
            s += step;
        }
        return step;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
