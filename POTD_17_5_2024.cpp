// POTD geeksforgeeks 17/05/2024
// Find Pair Given Difference

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

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = 1;

        while (right < n)
        {
            int diff = abs(arr[right] - arr[left]);
            if (diff == x)
            {
                return 1;
            }
            else if (diff < x)
            {
                right++;
            }
            else
            {
                left++;
                if (left == right)
                    right++;
            }
        }

        return -1;
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

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}
