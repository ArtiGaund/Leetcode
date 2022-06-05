class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0),cur(n+1,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int prev=index-1;prev>=-1;prev--)
            {
                int len=0+next[prev+1];
                if(prev==-1 or nums[index]>nums[prev])
                    len=max(len,1+next[index+1]);
                cur[prev+1]=len;
            }
            next=cur;
        }
        return next[0];
    }
};