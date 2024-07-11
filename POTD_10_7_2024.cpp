//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, std::vector<std::vector<int>> mat) {
        // Edge case: if the matrix is empty
        if (n == 0 && m == 0) return 0;

        // Create a dp matrix of the same size as mat initialized to 0
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        int maxSide = 0;

        // Fill the dp matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // The first row or first column can only form squares of side 1
                        dp[i][j] = 1;
                    } else {
                        // Use the minimum of the three neighboring squares plus 1
                        dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // Update the maximum side length
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }

        return maxSide;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends