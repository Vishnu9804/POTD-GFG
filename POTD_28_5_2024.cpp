// POTD geeksforgeeks 28/05/2024
// Minimum cost to fill given weight in a bag

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
    int minimumCost(int n, int w, vector<int> &cost)
    {
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 1; j <= w; ++j)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (i <= j && cost[i - 1] != -1 && dp[j - i] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - i] + cost[i - 1]);
                }
            }
        }

        return dp[w] == INT_MAX ? -1 : dp[w];
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

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}
