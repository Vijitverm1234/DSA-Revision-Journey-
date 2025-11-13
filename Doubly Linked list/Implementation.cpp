#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Insert node at the end of DLL
void insertNodeLast(Node*& head) {
    int el;
    cout << "Enter node value: ";
    cin >> el;

    Node* newNode = new Node(el);

    if (head == NULL) { // empty list
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Show DLL forward
void showLL(Node* head) {
    cout << "Forward Traversal: ";
    Node* temp = head;
    Node* last = NULL;

    // Forward traversal
    while (temp != NULL) {
        cout << temp->data << " ";
        last = temp;        // store the last node
        temp = temp->next;
    }
    cout << endl;

    // Backward traversal
    cout << "Backward Traversal: ";
    while (last != NULL) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}


int main() {
    Node* head = NULL;  // initially empty DLL

    while (true) {
        int flag;
        cout << "Enter 1 to insert, 0 to stop: ";
        cin >> flag;
        if (flag != 1) break;
        insertNodeLast(head);
    }

    showLL(head);
    return 0;
}
