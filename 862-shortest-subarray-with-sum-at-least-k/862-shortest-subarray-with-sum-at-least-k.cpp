class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long> prefix(n+1);
        for(int j=0;j<n;j++)
            prefix[j+1]=prefix[j]+(long)nums[j];
        deque<int> dq;
        int res=n+1;
        for(int j=0;j<=n;j++)
        {
            while(!dq.empty() and prefix[j]<=prefix[dq.back()]) dq.pop_back();
            while(!dq.empty() and prefix[j]>=prefix[dq.front()]+k)
            {
                res=min(res,j-dq.front());
                dq.pop_front();
            }
            dq.push_back(j);
        }
        return res<n+1?res:-1;
    }
};