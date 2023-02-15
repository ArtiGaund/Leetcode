class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    unordered_map<int,int> mp;
    int index=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        maxHeap.push({mp[val],{index,val}});
        index++;
    }
    
    int pop() {
        int num=maxHeap.top().second.second;
        mp[num]--;
        maxHeap.pop();
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */