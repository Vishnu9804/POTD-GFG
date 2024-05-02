#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node
{
    char data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data)
{
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL)
    {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
class Solution
{
public:
    void deleteVal(Node *&head, int val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *prevNode = head;
        Node *temp = head->next;

        while (temp != nullptr && temp->data != val)
        {
            prevNode = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;

        prevNode->next = temp->next;
        delete temp;
    }
    void insertAtFirst(Node *&head, int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }
    struct Node *arrangeCV(Node *head)
    {
        Node *temp = head;
        stack<char> st;
        while (temp)
        {
            if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
            {
                st.push(temp->data);
                Node *tempDelete = temp;
                temp = temp->next;
                deleteVal(head, tempDelete->data);
            }
            else
            {
                temp = temp->next;
            }
        }
        while (!st.empty())
        {
            insertAtFirst(head, st.top());
            st.pop();
        }
        return head;
    }
};
