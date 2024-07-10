// POTD geeksforgeeks 8/07/2024
// Closest Three Sum

//{ Driver Code Starts
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


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                int diff = abs(target - sum);

                if (diff < minDiff || (diff == minDiff && sum > closestSum)) {
                    closestSum = sum;
                    minDiff = diff;
                }

                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    // If the sum is exactly equal to the target, return the sum.
                    return sum;
                }
            }
        }

        return closestSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends