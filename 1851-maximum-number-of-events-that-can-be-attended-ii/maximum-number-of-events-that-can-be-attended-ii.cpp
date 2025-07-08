class Solution {
public:
    int binarySearch(int index,vector<vector<int>> &events,int val)
    {
        int low=index,high=events.size()-1;
        int req=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(events[mid][0]>val)
            {
                req=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return req;
    }
    int solve(int i,vector<vector<int>> &events,int k,vector<vector<int>> &dp)
    {
        if(i>=events.size() or k==0 or i==-1) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int index=binarySearch(i+1,events,events[i][1]);
        int c1=events[i][2]+solve(index,events,k-1,dp);
        int c2=solve(i+1,events,k,dp);
        return dp[i][k]=max(c1,c2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+5,vector<int>(k+1,-1));
        return solve(0,events,k,dp);
    }
};