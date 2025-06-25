#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

void getCenter(Node* head){
    if(head==NULL){
        cout<<"\nentered linked list is empty";
    }
    if (head->next == NULL) { 
        cout << "\nCenter Node: " << head->data;
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"\nCenter Node : "<<slow->data;

}
int main() {
    Node* head = NULL; // Initialize head to NULL
    int x;
    cout << "enter the value of head: ";
    cin >> x;

    // Create the head node
    head = new Node; // Allocate memory for head
    head->data = x;
    head->next = NULL;
    cout << "head pointer value: " << head->data << endl;

    Node* temp = head;
    while (true) {
        int x;
        cout << "enter the value of node: ";
        cin >> x;

        // Create new node
        Node* newnode = new Node; // Allocate memory for new node
        newnode->data = x;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        int y;
        cout << "\nDo you want to add more nodes (1 for yes, 0 for no): ";
        cin >> y;
        if (y != 1) {
            break;
        }
    }

    // Traversal of linked list
    cout << "\nEntered linked list: ";
    Node* temp2 = head;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;

 
    

    getCenter(head);
    return 0;
}