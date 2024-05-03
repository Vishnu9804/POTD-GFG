// POTD geeksforgeeks 2/05/2024
// Serialize and deserialize a binary tree

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    void serializeToVector(Node *root, vector<int> &a)
    {
        if (root == NULL)
        {
            a.push_back(-1);
            return;
        }
        a.push_back(root->data);

        serializeToVector(root->left, a);
        serializeToVector(root->right, a);
    }

    vector<int> serialize(Node *root)
    {
        vector<int> serial;
        serializeToVector(root, serial);

        return serial;
    }

    Node *buildTreeFromVector(vector<int> &a, int *index)
    {
        if (*index == a.size() or a[*index] == -1)
        {
            *index += 1;
            return NULL;
        }

        Node *root = new Node(a[*index]);
        *index += 1;

        root->left = buildTreeFromVector(a, index);
        root->right = buildTreeFromVector(a, index);
        return root;
    }

    Node *deSerialize(vector<int> &a)
    {
        int index = 0;
        return buildTreeFromVector(a, &index);
    }
};
