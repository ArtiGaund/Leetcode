class FreqStack {
public:
    //count of each element
    unordered_map<int,int> freq;
    //map elements with the same count
    //but the element which came at last will be at front
    unordered_map<int,stack<int>> group;
    int max_freq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        //increment the freq
        freq[val]++;
        //check this element has maxfreq
        max_freq=max(max_freq,freq[val]);
        //group in same count
        group[freq[val]].push(val);
    }
    
    int pop() {
        //find max occurrence element
        int top_max_freq=group[max_freq].top();
        //remove
        group[max_freq].pop();
        //decrease count
        freq[top_max_freq]--;
        if(group[max_freq].size()==0) max_freq--;
        return top_max_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */