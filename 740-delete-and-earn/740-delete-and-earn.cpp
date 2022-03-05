class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        if(nums.size()==0) return 0;
        vector<int> mp(n,0);
        for(int a:nums)
            mp[a]+=a;
        int one=mp[0];
        int two=max(one,mp[1]);
        for(int i=2;i<n;i++)
        {
            int cur=max(two,one+mp[i]);
            one=two;
            two=cur;
        }
        return max(one,two);
    }
};