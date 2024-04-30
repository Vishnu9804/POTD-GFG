// Delete every Kth Node of linked list

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
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

void append(struct Node **head_ref, struct Node **tail_ref, int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;

    *tail_ref = new_node;
}

class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        if (K == 1)
        {
            while (head != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            return nullptr;
        }

        if (K <= 0 || head == nullptr)
            return head;

        Node *temp = head;
        Node *prev = nullptr;

        int counter = 1;
        while (temp != nullptr)
        {
            if (counter == K)
            {
                if (prev == nullptr)
                {
                    Node *nextNode = temp->next;
                    delete temp;
                    head = nextNode;
                    temp = nextNode;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
                counter = 1;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                counter++;
            }
        }

        return head;
    }
};