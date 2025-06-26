#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

int getlen(Node* head){
 int count=0;
 Node* temp=head;
 while(temp!=NULL){
    count++;
    temp=temp->next;
 }
   return count;
}

void insertElement(Node* head){
   int x;
   cout<<"\n Enter the element to be inserted : ";
   cin>>x; 
   int y;
   cout<<"\n Enter the position : ";
   cin>>y;
   Node* newNode=new Node();
   newNode->data=x;
   newNode->next=NULL;
   int length=getlen(head);
   if(y>length){
    cout<<"\n not possible insertion";
   } 
   else{
    Node* temp=head;
    int count=1;
    while(count<=y-1){
        temp=temp->next;
        count+=1;
    }
    newNode->next=temp->next;
    temp->next=newNode;
      Node *temp2 = head;
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
   }
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
     int count=getlen(head);
     cout<<"\n length of Linked list"<<count;
     insertElement(head);
    return 0;
}