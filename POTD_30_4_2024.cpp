// POTD geeksforgeeks 30/04/2024
// Add Two Linked List

#include <iostream>
#include <vector>
#include <algorithm>

using namespace 

//#include <stdio.h>
//#include <stdlib.h>
//#include <string>
//#include <sstream>
//#include <queue>
//#include <map>

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

public:
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {

        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *res = NULL;
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry != 0)
        {

            int rem = carry;

            if (num1)
                rem += num1->data;
            if (num2)
                rem += num2->data;

            carry = rem / 10;

            rem = rem % 10;

            Node *newNode = new Node(rem);

            newNode->next = res;

            res = newNode;

            if (num1)
                num1 = num1->next;
            if (num2)
                num2 = num2->next;
        }
        while (res != NULL && res->data == 0)
        {
            Node *temp = res->next;
            res->next = NULL;
            delete (res);
            res = temp;
        }
        if (res == NULL)
            return new Node(0);
        return res;
    }
};
