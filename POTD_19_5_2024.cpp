// POTD geeksforgeeks 19/05/2024
// Find the closest number

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.findClosest(n, k, arr) << endl;
    }
}