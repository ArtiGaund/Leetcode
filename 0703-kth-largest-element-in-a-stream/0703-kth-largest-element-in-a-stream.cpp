class KthLargest {
public:
    struct numComp
    {
        bool operator()(const int &x,const int &y)
        {
            return x>y;
        }
    };
    priority_queue<int,vector<int>,numComp> minHeap;
    const int k;
    KthLargest(int k, vector<int>& nums):k(k) {
        for(int n:nums) add(n);
    }
    
    int add(int val) {
        minHeap.push(val);
        if((int)minHeap.size()>this->k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */