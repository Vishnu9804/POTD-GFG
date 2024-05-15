#include <bits/stdc++.h>
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
