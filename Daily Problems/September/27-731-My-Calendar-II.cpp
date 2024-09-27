class MyCalendarTwo {
public:
    set<pair<int, int>> overLapBookings;
    set<pair<int, int>> bookings;

    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for(auto &p: overLapBookings){
            if(isOverlap(p, start, end))
                return false;
        }

        for(auto &p: bookings){
            if(isOverlap(p, start, end)){
                overLapBookings.insert(getOverlapEvent(p, start, end));
            }
        }
        bookings.insert({start, end});
        return true;
        
    }
    bool isOverlap(pair<int, int> e, int start, int end){
        return max(e.first, start) < min(e.second, end);
    }
    pair<int, int> getOverlapEvent(pair<int, int> e, int start, int end){
        return {max(e.first, start), min(e.second, end)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
