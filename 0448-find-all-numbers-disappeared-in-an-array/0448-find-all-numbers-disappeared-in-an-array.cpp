class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        vector<int> res;
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1) res.push_back(i+1);
        return res;
    }
};