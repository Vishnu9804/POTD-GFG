#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &subtreeSize, int &removableEdges)
    {
        int size = 1;
        for (int neighbor : adj[node])
        {
            if (neighbor != parent)
            {
                size += dfs(neighbor, node, adj, subtreeSize, removableEdges);
            }
        }
        subtreeSize[node] = size;
        if (parent != -1 && size % 2 == 0)
        {
            removableEdges++;
        }

        return size;
    }

    int minimumEdgeRemove(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> subtreeSize(n + 1, 0);
        int removableEdges = 0;

        dfs(1, -1, adj, subtreeSize, removableEdges);

        return removableEdges;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }
        Solution obj;
        int ans = obj.minimumEdgeRemove(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
