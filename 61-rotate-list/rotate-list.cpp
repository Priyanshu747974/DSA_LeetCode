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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp= head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        int cntt=1;
        while(temp->next!=NULL){
            cntt++;
            temp=temp->next;
        }
         
        k=k%cntt;
        if(k==0){
            return head;
        }
        temp->next=head;
        ListNode* newTail=head;
        int steps=cntt-k;
        while(steps>1){
            newTail=newTail->next;
            steps--;
        }
        ListNode* newhead= newTail->next;
        newTail->next=NULL;
        return newhead;
    }
};