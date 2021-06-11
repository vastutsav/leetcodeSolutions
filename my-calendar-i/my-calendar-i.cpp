class MyCalendar {
map<int, int> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = bookings.upper_bound(start);
        if (next == bookings.end() || end <= next->second) {
            bookings[end] = start;
            return true;
        }
        else
            return false;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */