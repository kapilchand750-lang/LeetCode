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
        if(head==NULL || head->next==NULL || k==0) return head;
        int n = 1;
        ListNode*tail=head;
        while(tail->next!=NULL){
            n++;
            tail=tail->next;
        }
        k=k%n;
        if(k==0) return head;
        n=n-k;
        ListNode*temp=head;
        for(int i=1; i<n; i++) temp=temp->next;
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    } 
};