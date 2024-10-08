class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=mp.upper_bound(start);
        if(it==mp.end() or end<=it->second){
            mp[end]=start;
            return true;
        }else return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */