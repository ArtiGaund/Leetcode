class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int,int> count;
        for(int rank:ranks){
            count[rank]+=1;
        }
        auto comp = [](vector<long> &a,vector<long> &b){
            return a[0]>b[0];
        };
        priority_queue<vector<long>,vector<vector<long>>,decltype(comp)> minHeap(comp);
        for(auto it:count){
            int rank=it.first;
            minHeap.push({rank,rank,1,it.second});
        }
        long long time=0;
        while(cars>0){
            vector<long> cur=minHeap.top();
            minHeap.pop();
            time=cur[0];
            int rank=cur[1];
            long n=cur[2];
            int mechCount=cur[3];
            cars-=mechCount;
            n+=1;
            minHeap.push({rank*n*n,rank,n,mechCount});
        }
        return time;
    }
};