class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxlen=0,c=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            c+=(nums[i]==1?1:-1);
            if(mp.count(c)>0)
            {
                maxlen=max(maxlen,i-mp[c]);
            }
            else mp[c]=i;
        }
        return maxlen;
    }
};