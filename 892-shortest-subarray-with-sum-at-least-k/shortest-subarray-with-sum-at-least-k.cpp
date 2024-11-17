class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefixSums(n+1,0);
        for(int i=1;i<=n;i++) prefixSums[i]=prefixSums[i-1]+nums[i-1];
        deque<int> indices;
        int len=INT_MAX;
        for(int i=0;i<=n;i++){
            while(!indices.empty() and prefixSums[i]-prefixSums[indices.front()]>=k){
                len=min(len,i-indices.front());
                indices.pop_front();
            }
            while(!indices.empty() and prefixSums[i]<=prefixSums[indices.back()]){
                indices.pop_back();
            }
            indices.push_back(i);
        }
        return len==INT_MAX?-1:len;
    }
};