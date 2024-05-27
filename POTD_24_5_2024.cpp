// POTD geeksforgeeks 24/05/2024
// Partitions with Given Difference

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}