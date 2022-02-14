class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long> prefix(n+1,0);
        for(int i=0;i<n;i++)
            prefix[i+1]=prefix[i]+(long)nums[i];
        //want smallest y-x with p[y]-p[x]>=k
        int ans=n+1; // n+1 is impossible
        deque<int> dq; // opt for y
        for(int i=0;i<prefix.size();i++)
        {
            //want opt(y)=largest x with p[x]<=p[y]-k
            while(!dq.empty() and prefix[i]<=prefix[dq.back()]) dq.pop_back();
            while(!dq.empty() and prefix[i]>=prefix[dq.front()]+k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return ans<n+1?ans:-1;
    }
};