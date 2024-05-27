#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long max_Books(int arr[], int n, int k)
    {
        long long max_books = 0;
        long long current_books = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] <= k)
            {
                current_books += arr[i];
                max_books = max(max_books, current_books);
            }
            else
            {
                current_books = 0;
            }
        }
        return max_books;
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
