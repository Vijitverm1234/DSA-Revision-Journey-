#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

bool detectLoop(Node* head){
  Node* temp=head;
  Node* slow=head;
  Node* fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        return true;
    }
  }
  return false;
}
Node* getLoopHead(Node* head){
  Node* temp=head;
  Node* slow=head;
  Node* fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
  }
  return NULL;
}
int getLooplength(Node* head){
  Node* temp=head;
  Node* slow=head;
  Node* fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        int count=1;
        fast=fast->next;
        while(slow!=fast){
            count++;
            fast=fast->next;
        }
        return count;
    }
  }
  return 0;
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
    Node * temp3=NULL;
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp3=temp2;
        temp2 = temp2->next;
    }
    cout << endl;
    temp3->next=head;
    bool loop=detectLoop(head);
    if(loop){
        cout<<"\nloop detected";
        Node* loophead=getLoopHead(head);
        if(loophead){
            cout<<"\nLoop head : "<<loophead->data;
        }
        cout<<"\nLoop Length : "<<getLooplength(head);
    }
    else{
        cout<<"\n no loop in linked list";
    }
    
    return 0;
}