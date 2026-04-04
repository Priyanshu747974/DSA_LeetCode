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
    bool isPalindrome(ListNode* head) {
        stack< int > s;
        ListNode* temp= head;
        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }
        ListNode* temp2=head;
        while(temp2!=NULL){
            if(s.top()==temp2->val){
                temp2=temp2->next;
                s.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};