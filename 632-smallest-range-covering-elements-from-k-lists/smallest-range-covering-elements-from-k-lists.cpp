typedef pair<int,pair<int,int>> pii;
class Solution {
public:
    struct valComp{
        bool operator()(const pii &x,const pii &y){
            return x.first>y.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
      priority_queue<pii,vector<pii>,valComp> minHeap;
        int start=0,end=INT_MAX,curMax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(!nums[i].empty()){
                minHeap.push({nums[i][0],{i,0}});
                curMax=max(curMax,nums[i][0]);
            }
        }
        while(minHeap.size()==nums.size()){
            auto cur=minHeap.top();
            minHeap.pop();
            if(end-start>curMax-cur.first){
                start=cur.first;
                end=curMax;
            }
            cur.second.second++;
            if(nums[cur.second.first].size()>cur.second.second){
                cur.first=nums[cur.second.first][cur.second.second];
                minHeap.push(cur);
                curMax=max(curMax,cur.first);
            }
        }
        return {start,end};
    }
};