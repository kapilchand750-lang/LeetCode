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
private:
    ListNode* place(ListNode* head, int data, ListNode* curr){
        if(data<(head->val)){
            curr->next = head;
            return curr;
        }
        else{
            ListNode * temp = head;
            ListNode * prev = head;
            while(temp!=NULL && (temp->val<=data)){
                prev = temp;
                temp = temp->next;
            }
            prev->next = curr;
            curr->next = temp;   
        }
        return head;
    }
public:
    ListNode* insertionSortList(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = head;
        ListNode * curr = head->next;
        while(curr){
            if(prev->val<=curr->val){
                prev = curr;
                curr = curr->next;
            }else{
                prev->next = NULL;
                ListNode * temp = curr->next;
                head = place(head, curr->val, curr);
                prev->next = temp;
                curr = temp;
            }
        }
        return head;
    }
};