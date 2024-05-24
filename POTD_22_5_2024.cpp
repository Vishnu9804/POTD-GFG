// POTD geeksforgeeks 22/05/2024
// Minimize Max Distance to Gas Station

#include <bits/stdc++.h>
using namespace std;

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        double low = 0.0;
        double high = stations[n - 1] - stations[0];
        const double eps = 1e-6;

        auto feasible = [&](double d) -> bool
        {
            int count = 0;
            for (int i = 1; i < n; ++i)
            {
                int requiredStations = static_cast<int>((stations[i] - stations[i - 1]) / d);
                count += requiredStations;
                if (count > k)
                    return false;
            }
            return true;
        };

        while (high - low > eps)
        {
            double mid = (low + high) / 2.0;
            if (feasible(mid))
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return round(high * 100.0) / 100.0;
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
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
