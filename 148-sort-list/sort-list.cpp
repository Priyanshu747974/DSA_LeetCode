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
    ListNode* findmid(ListNode* head){
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* temp= new ListNode(-1,NULL);
        ListNode* dummynode= temp;
        
        while(list1!=NULL && list2!=NULL){
            if(list1-> val < list2-> val){
                dummynode->next=list1;
                list1=list1->next;
            }
            else{
                dummynode->next=list2;
                list2=list2->next;
            }
            dummynode = dummynode->next;
        }
            if(list1!=NULL){
                dummynode->next=list1;
            }
            else {
                dummynode->next=list2;
            }
        return temp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid= findmid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        ListNode* left= head;
        
        left=sortList(left);
        right=sortList(right);
        
        return merge(left, right);
    }
};