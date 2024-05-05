#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

class Solution
{
public:
    Node *buildTreeUtil(int in[], int post[], int inStrt, int inEnd, int *index)
    {
        if (inStrt > inEnd)
            return NULL;

        Node *tNode = new Node(post[*index]);
        (*index)--;

        if (inStrt == inEnd)
            return tNode;

        int inIndex = search(in, inStrt, inEnd, tNode->data);
        tNode->right = buildTreeUtil(in, post, inIndex + 1, inEnd, index);
        tNode->left = buildTreeUtil(in, post, inStrt, inIndex - 1, index);

        return tNode;
    }

    int search(int arr[], int strt, int end, int value)
    {
        int i;
        for (i = strt; i <= end; i++)
        {
            if (arr[i] == value)
                return i;
        }
    }

    Node *buildTree(int in[], int post[], int n)
    {
        int index = n - 1;
        return buildTreeUtil(in, post, 0, n - 1, &index);
    }
};
