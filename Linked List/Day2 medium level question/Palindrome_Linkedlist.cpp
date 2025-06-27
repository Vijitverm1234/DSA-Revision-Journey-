#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

Node* getCenter(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head; 
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* temp = head;
    while (temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev; 
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }

    Node* slow = getCenter(head);
    Node* second_half = slow->next; 
    slow->next = NULL;

    second_half = reverseLinkedList(second_half);

    Node* first_half = head;
    while (second_half != NULL) {
        if (first_half->data != second_half->data) {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    int x;
    cout << "Enter the value of head: ";
    cin >> x;

    head = new Node;
    head->data = x;
    head->next = NULL;

    Node* temp = head;
    while (true) {
        cout << "Enter the value of node: ";
        cin >> x;

        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;

        temp->next = newnode;
        temp = newnode;

        int y;
        cout << "Do you want to add more nodes (1 for yes, 0 for no): ";
        cin >> y;
        if (y != 1) {
            break;
        }
    }

    cout << "\nLinked List: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "\nThe linked list is a palindrome" << endl;
    } else {
        cout << "\nThe linked list is not a palindrome" << endl;
    }

    freeList(head);

    return 0;
}