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
        if(head==NULL || head->next==NULL) return head;
        ListNode*curr=head, *temp=head, *prev=NULL;
        while(curr!=NULL){
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    ListNode* findKth(ListNode*head, int k){
        for(int i=1; i<k && head!=NULL; i++) head=head->next;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL ||k<=1) return head;
        ListNode*temp=head, *kth=NULL, *prev=NULL, *nextNode=NULL;
        while(temp!=NULL){
            kth=findKth(temp,k);
            if(kth==NULL){
                if(prev) prev->next=temp;
                break;
            }
            nextNode=kth->next;
            kth->next=NULL;
            kth=reverse(temp);
            if(head==temp) head=kth;
            else prev->next=kth;
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};