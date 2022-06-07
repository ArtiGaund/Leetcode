class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        for(int a:nums) res=max(a,res);
        int curMin=1,curMax=1;
        for(int a:nums)
        {
            if(a==0)
            {
                curMax=1;
                curMin=1;
                continue;
            }
            int temp=curMax*a;
            curMax=max({curMax*a,curMin*a,a});
            curMin=min({temp,curMin*a,a});
            res=max(res,curMax);
        }
        return res;
    }
};