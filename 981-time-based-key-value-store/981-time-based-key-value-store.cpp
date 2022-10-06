class TimeMap {
public:
    unordered_map<int, unordered_map<string,string>> m;

TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    unordered_map<string,string> temp;
    temp[key] = value;
    m[timestamp] = temp;
}

string get(string key, int timestamp) {
    
    for(int i=timestamp; i>=1; i--){
        if(m.find(i) != m.end()){
            auto x = m[i];
            if(x.find(key) != x.end()){
                return x[key];
            }
        }
    }
    return "";
}
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */