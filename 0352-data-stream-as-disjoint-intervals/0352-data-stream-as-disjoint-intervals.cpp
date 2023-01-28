class SummaryRanges {
public:
    map<int,int> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left=value,right=value;
        auto small_entry=intervals.upper_bound(value);
        if(small_entry!=intervals.begin())
        {
            auto max_entry=small_entry;
            --max_entry;
            if(max_entry->second>=value) return;
            if(max_entry->second==value-1) left=max_entry->first;
        }
        if(small_entry!=intervals.end() and small_entry->first==value+1)
        {
            right=small_entry->second;
            intervals.erase(small_entry);
        }
        intervals[left]=right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto p:intervals)
            res.push_back({p.first,p.second});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */