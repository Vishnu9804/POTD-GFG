// POTD geeksforgeeks 3/07/2024
// Remove all occurences of duplicates in a linked list

//{ Driver Code Starts
// Initial Template for C++

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

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        if (!head || !head->next) {
            return head;
        }

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        Node* current = head;

        while (current) {
            bool isDuplicate = false;
            while (current->next && current->data == current->next->data) {
                isDuplicate = true;
                current = current->next;
            }

            if (isDuplicate) {
                prev->next = current->next;
            } else {
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy.next;
    }
};


//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends