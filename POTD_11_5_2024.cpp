#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> jugglerSequence(long long n)
    {
        vector<long long> output;
        output.push_back(n);
        while (n > 1)
        {
            if (n % 2)
            {
                n = (sqrt(n) * n);
            }
            else
            {
                n = sqrt(n);
            }
            output.push_back(n);
        }
        return output;
    }
};