/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* getkthNode(ListNode* head,int k){
        k-=1;
        ListNode* temp=head;
        while( temp!=NULL  && k>0){
            k-=1;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL){
            ListNode* kthNode=getkthNode(temp,k);
            if(kthNode==NULL){
                if(prevLast){
                    prevLast->next=temp;
                }
                break;
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevLast->next=kthNode;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};
