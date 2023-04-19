class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int min=(int)(n/3)+1;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==min) res.push_back(nums[i]);
            if(res.size()==2) break;
        }
        return res;
    }
};