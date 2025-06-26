#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

void reverseLinkedList(Node* head){
    if(head==NULL || head->next==NULL){
        cout<<"not enough nodes in linked list";
    }
    else{
        Node* temp=new Node();
        Node* prev=new Node();
        prev=NULL;
        temp=head;
        while(temp!=NULL){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        Node* temp2=prev;
        cout<<"\nreversed linked list : ";
        while(temp2!=NULL){
            cout<<temp2->data<<" ";
            temp2=temp2->next;
        }
    }
}
Node* aggregateEvenOdd(Node* head) {
    if (!head || !head->next) return head;

    Node *even = nullptr, *evenTail = nullptr;
    Node *odd = nullptr, *oddTail = nullptr;
    Node *curr = head;

    while (curr) {
        Node *next = curr->next;
        curr->next = nullptr;

        if (curr->data % 2 == 0) {
            if (!even) even = evenTail = curr;
            else evenTail = evenTail->next = curr;
        } else {
            if (!odd) odd = oddTail = curr;
            else oddTail = oddTail->next = curr;
        }
        curr = next;
    }

    if (evenTail) evenTail->next = odd;
    Node* temp1=even ? even : odd;
    printList(temp1);
    return temp1;
}
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
    int main()
{
    Node *head = NULL;
    int x;
    cout << "enter the value of head: ";
    cin >> x;

    head = new Node;
    head->data = x;
    head->next = NULL;
    cout << "head pointer value: " << head->data << endl;

    Node *temp = head;
    while (true)
    {
        int x;
        cout << "enter the value of node: ";
        cin >> x;

        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        int y;
        cout << "\nDo you want to add more nodes (1 for yes, 0 for no): ";
        cin >> y;
        if (y != 1)
        {
            break;
        }
    }

    cout << "\nEntered linked list: ";
    Node *temp2 = head;
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    reverseLinkedList(head);
    cout<<"\nAggreagted list :";
    aggregateEvenOdd(head);
    
    return 0;
}