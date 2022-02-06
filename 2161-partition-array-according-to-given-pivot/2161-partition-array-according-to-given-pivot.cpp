class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low=0,same=0,high=nums.size();
        for(int a:nums)
        {
            if(a<pivot) same++;
            else if(a>pivot) high--;
        }
        vector<int> res(nums.size());
        for(int a:nums)
        {
            if(a<pivot) res[low++]=a;
            else if(a==pivot) res[same++]=a;
            else res[high++]=a;
        }
        return res;
    }
};