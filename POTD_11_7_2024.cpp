// POTD geeksforgeeks 11/07/2024
// Maximum Connected group

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  
private:
    class UnionFind {
    public:
        UnionFind(int n) : parent(n), size(n, 1) {
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }

        int getSize(int x) {
            return size[find(x)];
        }

    private:
        vector<int> parent;
        vector<int> size;
    };

public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        UnionFind uf(n * n);
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto index = [n](int x, int y) { return x * n + y; };
        
        // Step 1: Union all adjacent 1's
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (auto& dir : directions) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            uf.unionSets(index(i, j), index(ni, nj));
                        }
                    }
                }
            }
        }
        
        // Step 2: Find the largest component of 1's
        int maxConnected = 0;
        unordered_map<int, int> componentSize;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int root = uf.find(index(i, j));
                    componentSize[root] = uf.getSize(root);
                    maxConnected = max(maxConnected, componentSize[root]);
                }
            }
        }
        
        // Step 3: Try changing each 0 to 1 and calculate the possible new component size
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int newSize = 1; // Including the current cell
                    
                    for (auto& dir : directions) {
                        int ni = i + dir.first, nj = j + dir.second;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int root = uf.find(index(ni, nj));
                            if (seen.find(root) == seen.end()) {
                                seen.insert(root);
                                newSize += uf.getSize(root);
                            }
                        }
                    }
                    
                    maxConnected = max(maxConnected, newSize);
                }
            }
        }
        
        return maxConnected;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends