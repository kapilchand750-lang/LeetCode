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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0, carry=0, digit=0;
        ListNode*head=NULL;
        ListNode*temp=head;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL) sum=l2->val+carry;
            else if(l2==NULL) sum=l1->val+carry;
            else sum=l1->val+l2->val+carry;
            digit=sum%10;
            carry=sum/10;
            ListNode*news = new ListNode(digit);
            if(temp==NULL){
                head=temp=news;
            }
            else{
                temp->next=news;
                temp=temp->next;
            }
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }  
        if(carry>=1)  {
            ListNode*news = new ListNode(carry);
            temp->next=news;
        }
        return head;
    }
};