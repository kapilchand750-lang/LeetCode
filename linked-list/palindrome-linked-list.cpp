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
        if(head){
            ListNode*curr=head;
            ListNode*temp=curr;
            ListNode*prev=NULL;
            while(temp!=NULL){
                temp=temp->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            return prev;
        }
        return head;
    }

    bool isPalindrome(ListNode* head) {
            ListNode*slow=head;
            ListNode*fast=head;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode*second=reverse(slow);
            slow->next=NULL;
            ListNode*first=head;
            ListNode*temp=second;
            while(temp!=NULL){
                if(first->val != temp->val) {
                    reverse(second);
                    return 0;
                }
                first = first->next;
                temp = temp->next;
            }
            reverse(second);
        return 1;
    }
};