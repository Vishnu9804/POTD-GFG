// POTD geeksforgeeks 11/05/2024
// Juggler Sequence

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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
