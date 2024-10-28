class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int num:nums){
            int root=(int)sqrt(num);
            if(root*root==num and mp.find(root)!=mp.end()){
                mp[num]=mp[root]+1;
            }else{
                mp[num]=1;
            }
        }
        int longest=0;
        for(auto it:mp){
            longest=max(longest,it.second);
        }
        return longest==1?-1:longest;
    }
};