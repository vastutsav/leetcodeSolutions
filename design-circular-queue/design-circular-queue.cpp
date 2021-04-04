class MyCircularQueue {

    private:
    vector <int> cq;
    int head = 0, tail = 0;
    bool reset = true;

    public:
    MyCircularQueue(int k) {
        cq.resize(k);
        head = 0,tail = 0;
        reset = true;
    }
    
    void myPrint(string func)
    {
        cout << "========\n";
        cout << "In function : " << func << "\n";
        cout << "head = <" << head << ">\n";
        cout << "tail = <" << tail << ">\n";
        for (int i = head; i != tail; i = (i+cq.size()+1)%cq.size()) {
            cout << "i = <" << i << ">; value = <" << cq[i] << ">\n";
        }
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            cq[tail]=value;
            tail = (tail + 1 + cq.size())%cq.size();
            if (reset) reset = false;
            //myPrint("enQueue");
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            head = (cq.size() + head + 1) % cq.size();
            if (head == tail) reset = true;
            //myPrint("deQueue");
            return true;
        }
        return false;

    }
    
    int Front() {
        if (isEmpty()) return -1;
        
        return cq[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        
        return cq[(tail -1 + cq.size()) % cq.size()];
    }
    
    bool isEmpty() {
        return head == tail && reset;
    }
    
    bool isFull() {
        if (tail == head && !reset)
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */