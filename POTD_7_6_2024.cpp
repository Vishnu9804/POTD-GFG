// POTD geeksforgeeks 07/06/2024
// Maximum occured integer

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
    int arr[1000000];

    int maxOccured(int n, int l[], int r[], int maxx)
    {
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < n; i++)
        {
            arr[l[i]] += 1;
            arr[r[i] + 1] -= 1;
        }

        int msum = arr[0], ind = 0;
        for (int i = 1; i <= maxx; i++)
        {
            arr[i] += arr[i - 1];

            if (msum < arr[i])
            {
                msum = arr[i];
                ind = i;
            }
        }

        return ind;
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
        int l[n];
        int r[n];

        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int maxx = 0;
        for (int i = 0; i < n; i++)
        {

            cin >> r[i];
            if (r[i] > maxx)
            {
                maxx = r[i];
            }
        }
        Solution ob;
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
