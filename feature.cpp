#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int val) {
        this->val = val;
        next = random = NULL;
    }
};

// Function to copy the linked list with random pointers
Node* copylistrandom(Node* head) {
    if (!head) return NULL;

    // Step 1: Create a deep copy of each node and insert it right after the original node.
    Node* temp = head;
    while (temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    // Step 2: Assign the random pointers for the deep copies.
    temp = head;
    while (temp != NULL) {
        if (temp->random != NULL) {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    // Step 3: Separate the deep copy list from the original list.
    Node* dummy = new Node(-1);
    Node* copyTemp = dummy;
    temp = head;
    while (temp != NULL) {
        copyTemp->next = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        copyTemp = copyTemp->next;
    }

    return dummy->next;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(80);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* tail = new Node(70);
    
    // Next connections
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = tail;
    
    // Random connections
    head->random = c;
    a->random = b;
    b->random = e;
    c->random = f;
    e->random = f;
    
    cout << "Original list:\n";
    display(head);
    
    Node* copiedHead = copylistrandom(head);
    
    cout << "Copied list:\n";
    display(copiedHead);
    
    return 0;
}
