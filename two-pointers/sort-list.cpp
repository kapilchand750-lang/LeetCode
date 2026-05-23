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
     ListNode* middleFind(ListNode* head){
        if(head && head->next!=NULL){
            ListNode*slow=head;
            ListNode*fast=head->next;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
        return head;
    }

    ListNode* merge(ListNode* left, ListNode* right){
       ListNode*head=NULL;
       ListNode*temp=NULL;
       while(left!=NULL && right!=NULL){
        if(left->val>right->val){
            if(head==NULL) head=temp=right;
            else{
                temp->next=right;
                temp=temp->next;
            }
            right=right->next;
        }
        else{
            if(head==NULL) head=temp=left;
            else{
                temp->next=left;
                temp=temp->next;
            }
            left=left->next;
        }
        }
        if(left!=NULL) temp->next=left;
        else temp->next=right;
        return head;
       }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*left=NULL;
        ListNode*right=NULL;
        ListNode*middle=middleFind(head);
        right=middle->next;
        middle->next=NULL;
        left=sortList(head);
        right=sortList(right);
        return merge(left,right);
    }
};