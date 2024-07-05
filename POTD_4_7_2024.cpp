// POTD geeksforgeeks 4/07/2024
// Duplicate Subtrees

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

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = "";
        currVal += ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void preorder(Node* root, vector<int>& temp) {
    if (!root) {
        return;
    }
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}

class Solution {
    unordered_map<string, int> subtreeMap;
    vector<Node*> duplicateRoots;

    string serialize(Node* root) {
        if (!root)
            return "#";
        string s = to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
        if (subtreeMap[s] == 1)
            duplicateRoots.push_back(root);
        subtreeMap[s]++;
        return s;
    }

  public:
    vector<Node*> printAllDups(Node* root) {
        subtreeMap.clear();
        duplicateRoots.clear();
        serialize(root);
        return duplicateRoots;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string treeString;
        getline(cin >> ws, treeString);
        Node* root = buildTree(treeString);
        Solution obj;
        vector<Node*> res = obj.printAllDups(root);

        vector<vector<int>> ans;
        for (int i = 0; i < res.size(); i++) {
            vector<int> temp;
            preorder(res[i], temp);
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
