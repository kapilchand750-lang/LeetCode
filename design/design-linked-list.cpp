

class MyLinkedList {
public:
    struct Node {
    public:
    int val;
    Node * next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
    Node * head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        int i = 0;
        if(index<0 || index>=size) return -1;
        Node * temp = head;
        while(i<index){
            temp=temp->next;
            i++;
        }
        return temp->val;  
    }
    
    void addAtHead(int val) {
        Node * newNode = new Node(val);
        Node * temp = head;
        newNode->next = head;
        head= newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if(head==NULL) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        if(index == 0) addAtHead(val); 
        else if(index == size) addAtTail(val);
        else{
            Node*temp = head;
            int i = 0;
            while(i<index-1){
                temp = temp->next;
                i++;
            }
            Node * newNode = new Node(val);
            newNode->next = temp->next;
            temp->next= newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size || size==0) return;
        if(index==0){
            Node * del = head;
            head = head->next;
            delete del;
        }
        else {
            int i = 0;
            Node * temp = head;
            while(i<index-1){
                temp = temp->next;
                i++;
            }
            Node * del = temp->next;
            temp->next = del->next;
            delete del;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */