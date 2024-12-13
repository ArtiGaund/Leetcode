class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto comp=[](pair<int,int> &a,pair<int,int> &b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long res=0;
        vector<bool> marked(nums.size(),false);
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int num=ele.first;
            int index=ele.second;
            if(!marked[index]){
                res+=num;
                marked[index]=true;
                if(index-1>=0) marked[index-1]=true;
                if(index+1<nums.size()) marked[index+1]=true;
            }
        }
        return res;
    }
};