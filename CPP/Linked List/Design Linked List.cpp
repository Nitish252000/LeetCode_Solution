class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    int get(int index) {
        if(index<0 || index>size){
            return -1;
        }
        int cnt =0;
        Node* temp = head;
        while(temp!=NULL){
            if(cnt == index){
                return temp->val;
            }
            temp=temp->next;
            cnt++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
       size++;
    }

    void addAtTail(int val) {    
        Node* newNode = new Node(val);
        if (head == NULL) {
            tail = head = newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index<0 || index > size) {
            return;
        }
        if (index == 0) { // before head
            addAtHead(val);
            return;
        }
        if (size == index) { // After Tail
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head; // In between
        int cnt = 0;
        while (cnt != index - 1) {
            temp = temp->next;
            cnt++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    void deleteAtHead(int index) {
        if (head == tail) { // single node
            delete head;
            head = tail = nullptr;
        }else{
            Node* to_del = head;
            head = head->next;
            to_del->next = NULL;
            delete to_del;
        }       
        size--;
    }
    void deleteAtTail(int index){
        if(tail == head){
            delete tail;
            head= tail =NULL;
        }else{
            Node* temp = head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            temp->next =NULL;
            tail =temp;
        }
        size--;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        if (index == 0) { // delete head;
            deleteAtHead(index);
            return;
        }
        if (index == size-1) { // At Tail
            deleteAtTail(index);
            return;
        }
        // Inside
        Node* temp = head;
        int cnt = 0;
        while (cnt != index - 1) {
            temp = temp->next;
            cnt++;
        }
        Node* to_del = temp->next;
        temp->next = to_del->next;
        delete to_del;
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
