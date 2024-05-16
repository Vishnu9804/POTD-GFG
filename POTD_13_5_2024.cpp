// POTD geeksforgeeks 13/05/2024
// Number of Good Components

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

class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// } Driver Code Ends

class Solution
{
public:
    void dfsTraversal(int vertex, int &numVertices, int &numEdges, const vector<vector<int>> &adjacencyList, vector<bool> &visited)
    {
        visited[vertex] = true;
        numVertices++;
        numEdges += adjacencyList[vertex].size();
        for (int neighbor : adjacencyList[vertex])
        {
            if (!visited[neighbor])
            {
                dfsTraversal(neighbor, numVertices, numEdges, adjacencyList, visited);
            }
        }
    }

    int findNumberOfGoodComponent(int totalEdges, int totalVertices, vector<vector<int>> &graph)
    {
        vector<vector<int>> adjList(totalVertices + 1);
        for (const auto &edge : graph)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int goodComponentCount = 0;
        vector<bool> visited(totalVertices + 1, false);

        for (int i = 1; i <= totalVertices; i++)
        {
            if (!visited[i])
            {
                int verticesCount = 0, edgesCount = 0;
                dfsTraversal(i, verticesCount, edgesCount, adjList, visited);
                edgesCount /= 2;
                if (edgesCount == (verticesCount * (verticesCount - 1)) / 2)
                    goodComponentCount++;
            }
        }
        return goodComponentCount;
    }
};
