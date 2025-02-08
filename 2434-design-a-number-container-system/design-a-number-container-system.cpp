class NumberContainers {
public:
unordered_map<int,priority_queue<int,vector<int>,greater<int>>> noToIndices;
unordered_map<int,int> indexToNos;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indexToNos[index]=number;
        noToIndices[number].push(index);
    }
    
    int find(int number) {
        if(noToIndices.find(number)==noToIndices.end()) return -1;
        auto &minheap=noToIndices[number];
        while(!minheap.empty()){
            int index=minheap.top();
            if(indexToNos[index]==number) return index;
            minheap.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */