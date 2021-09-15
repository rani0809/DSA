/*  In this code we are going to create a Linked list with three nodes. */

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

int main() {

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;         // assign data to first node
    head->next = second;    // Link first node with second node

    second->data = 2;       // assign data to second node
    second->next = third;   // Link second node with third node

    third->data = 3;        // assign data to third node
    third->next = NULL;     // We ground/null the last node

    return 0;
}
