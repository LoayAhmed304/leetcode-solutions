class MyCalendar {
public:
    vector<pair<int,int>>m;
    MyCalendar() {    }
    
    bool book(int start, int end) {
        for(auto& p: m){
            if(start < p.second && end > p.first){
                return false;
            }
        }
        m.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
