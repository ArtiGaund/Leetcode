class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyTimeMp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(keyTimeMp.find(key)==keyTimeMp.end()) return "";
        if(timestamp<keyTimeMp[key][0].first) return "";
        int left=0,right=keyTimeMp[key].size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(keyTimeMp[key][mid].first<=timestamp) left=mid+1;
            else right=mid;
        }
        if(right==0) return "";
        return keyTimeMp[key][right-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */