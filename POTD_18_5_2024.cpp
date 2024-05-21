#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &a)
    {
        int left = 0, right = a.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (a[mid] < a[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return a[left];
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        int ans = ob.findPeakElement(a);
        cout << ans << "\n";
    }
    return 0;
}
