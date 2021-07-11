class MedianFinder {
    priority_queue <int> maxHeap;
    priority_queue <int, vector <int>, greater <int>> minHeap;
    int count = 0;
    int med1, med2;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        this->count = 0;
        this->med1 = -1*10e5;
        this->med2 = -1*10e5;
        // cout << "MedianFinder " << isOdd << endl;
    }
    
    void addNum(int num) {
        int minTop, maxTop;
        if (count < 1) 
            med1 = num;
        
        if (count >= 1) {
            if (count%2 == 1) { // odd
                med2 = num;
                if (med2 < med1)
                    swap(med1, med2);
                maxHeap.push(med1);
                minHeap.push(med2);
            } else { // even
                
                minTop = minHeap.top();
                maxTop = maxHeap.top();
                // cout << " num " << num << " minT " << minTop << "maxT " << maxTop << endl;
                if (num <= maxTop) {
                    //cout << "num <= maxTop\n";
                    med1 = maxTop;
                    maxHeap.pop();
                    maxHeap.push(num);
                } else if (num >= minTop) {
                    //cout << "num >= minTop\n";
                    med1 = minTop;
                    minHeap.pop();
                    minHeap.push(num);
                } else {
                    med1 = num;
                }
            }
        }
        ++count;
    }
    
    double findMedian() {
        return (count%2 == 1)?med1:((maxHeap.top()+minHeap.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */