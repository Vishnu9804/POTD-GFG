#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long max_Books(int arr[], int n, int k)
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
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}