#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;


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
    
    
    return 0;
}