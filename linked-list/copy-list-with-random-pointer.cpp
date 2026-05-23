/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node*temp=head;
        while(temp!=NULL){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->next->random=temp->random?temp->random->next:NULL;
            temp=temp->next->next;
        }
        temp=head;
        Node dum(0);
        Node*d1 = &dum;
        while(temp!=NULL){
            d1->next=temp->next;
            temp->next=temp->next?temp->next->next:NULL;
            d1=d1->next;
            temp=temp->next;
        }
        return dum.next;
    }
};