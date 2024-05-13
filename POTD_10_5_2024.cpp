// POTD geeksforgeeks 10/05/2024
// Combination Sum II

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
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        vector<vector<int>> result;
        vector<int> current;
        sort(arr.begin(), arr.end());
        backtrack(arr, k, 0, current, result);
        return result;
    }

    void backtrack(vector<int> &arr, int target, int start, vector<int> &current, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        if (target < 0)
            return;

        for (int i = start; i < arr.size(); ++i)
        {
            if (i > start && arr[i] == arr[i - 1])
                continue;
            current.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, current, result);
            current.pop_back();
        }
    }
};
