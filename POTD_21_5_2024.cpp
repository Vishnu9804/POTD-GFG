#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printKClosest(vector<int> numbers, int size, int kValue, int target)
    {
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}