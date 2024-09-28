struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = nullptr, Node* prev = nullptr): val(val), next(next), prev(prev){}
};

class MyCircularDeque {
    private:
    Node* head;
    Node* rear;
    int size;
    int capacity;
public:
    MyCircularDeque(int k) {
        head = nullptr;
        rear = nullptr;
        size = 0;
        capacity = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(!head){
            head = new Node(value);
            rear = head;
        } else {
            Node* newNode = new Node(value, head, nullptr);
            head->prev = newNode;
            head = newNode;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(!head){
            head = new Node(value);
            rear = head;
        } else{
            Node* newNode = new Node(value, nullptr, rear);
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(size == 1){
            head = nullptr;
            rear = nullptr;
        } else{
            Node* temp = head->next;
            delete head;
            head = temp;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(size == 1){
            head = nullptr;
            rear = nullptr;
        }else{
            Node* temp = rear->prev;
            delete rear;
            rear = temp;
        }
        size--;
        return true;
    }
    
    int getFront() {
        return isEmpty()? -1 : head->val;
    }
    
    int getRear() {
        return isEmpty() ? -1 : rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
