class Solution {
public:
    int rev(int num){
        int res=0;
        while(num>0){
            res=res*10+num%10;
            num/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
            temp.push_back(nums[i]-rev(nums[i]));
        unordered_map<int,int> mp;
        int res=0;
        int mod=1e9+7;
        for(int num:temp){
            res=(res+mp[num])%mod;
            mp[num]++;
        }
        return res;
        
    }
};