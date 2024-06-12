// POTD geeksforgeeks 11/06/2024
// Maximum Tip Calculatonation

#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<tuple<int, int, int, int>> tips;

        for (int i = 0; i < n; i++)
        {
            tips.push_back(make_tuple(abs(arr[i] - brr[i]), arr[i], brr[i], i));
        }

        sort(tips.rbegin(), tips.rend());

        long long totalTip = 0;
        int countA = 0, countB = 0;

        for (auto &tip : tips)
        {
            int diff, aTip, bTip, idx;
            tie(diff, aTip, bTip, idx) = tip;

            if ((aTip >= bTip && countA < x) || countB >= y)
            {
                totalTip += aTip;
                countA++;
            }
            else
            {
                totalTip += bTip;
                countB++;
            }
        }

        return totalTip;
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}
