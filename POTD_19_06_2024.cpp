// POTD geeksforgeeks 19/06/2024
// Find maximum volume of a cuboid

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
    double maxVolume(double perimeter, double area)
    {
        double ans =
            (pow((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12, 2) *
             ((perimeter / 4) -
              (2 * ((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12))));
        return ans;
    }
};

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        double perimeter, area;
        cin >> perimeter >> area;
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
