class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> pos(size/2),neg(size/2);
        int p=0,n=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]>=0) pos[p++]=nums[i];
            else neg[n++]=nums[i];
        }
        // nums.clear();
        p=0;
        n=0;
        int i=0;
        while(i<size)
        {
            nums[i++]=pos[p++];
            nums[i++]=neg[n++];
        }
        return nums;
    }
};