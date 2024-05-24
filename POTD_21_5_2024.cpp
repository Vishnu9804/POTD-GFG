// POTD geeksforgeeks 21/05/2024
// K closest elements

#include <bits/stdc++.h>
using namespace std;

//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

class Solution
{
public:
    vector<int> printKClosest(vector<int> numbers, int size, int kValue, int target)
    {
        vector<int> result;
        vector<int> closestValues;

        int left = findCrossOver(numbers, 0, size - 1, target);

        int right = left + 1;
        int counter = 0;

        if (numbers[left] == target)
        {
            left--;
        }

        while (left >= 0 && right < size && counter < kValue)
        {
            if (target - numbers[left] < numbers[right] - target)
            {
                closestValues.push_back(numbers[left]);
                left--;
            }
            else
            {
                closestValues.push_back(numbers[right]);
                right++;
            }
            counter++;
        }

        while (counter < kValue && left >= 0)
        {
            closestValues.push_back(numbers[left]);
            left--;
            counter++;
        }

        while (counter < kValue && right < size)
        {
            closestValues.push_back(numbers[right]);
            right++;
            counter++;
        }

        for (int i = 0; i < kValue; i++)
        {
            result.push_back(closestValues[i]);
        }

        return result;
    }

    int findCrossOver(vector<int> &values, int lower, int higher, int target)
    {
        if (values[higher] <= target)
        {
            return higher;
        }
        if (values[lower] > target)
        {
            return lower;
        }
        int mid = (lower + higher) / 2;
        if (values[mid] <= target && values[mid + 1] > target)
        {
            return mid;
        }
        else if (values[mid] < target)
        {
            return findCrossOver(values, mid + 1, higher, target);
        }
        return findCrossOver(values, lower, mid - 1, target);
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
