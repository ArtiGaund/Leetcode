class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> minHeap(nums.begin(),nums.end());
        int no_operations=0;
        while(minHeap.top()<k){
            long x=minHeap.top();
            minHeap.pop();
            long y=minHeap.top();
            minHeap.pop();
            minHeap.push(min(x,y)*2+max(x,y));
            no_operations++;
        }
        return no_operations;
    }
};