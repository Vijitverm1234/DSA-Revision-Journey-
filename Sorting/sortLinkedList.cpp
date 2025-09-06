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
    ListNode* mergeLL(ListNode* list1, ListNode* list2){
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
         if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
        return dummy->next;
    }
    ListNode* midLL(ListNode* head){
         if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* sortLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* mid=midLL(head);
        
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left=head;

        left=sortLL(left);
        right=sortLL(right);
        return mergeLL(left,right);
    }
    ListNode* sortList(ListNode* head) {
        head = sortLL(head);
        return head;
    }
};
