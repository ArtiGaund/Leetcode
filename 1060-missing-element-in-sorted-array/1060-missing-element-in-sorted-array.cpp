class Solution {
public:
    int missing(int index,vector<int> nums)
    {
        return nums[index]-nums[0]-index;
    }
    int missingElement(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>missing(n-1,nums)) 
            return nums[n-1]+k-missing(n-1,nums);
        int left=0,right=n-1,pivot;
        while(left!=right)
        {
            pivot=left+(right-left)/2;
            if(missing(pivot,nums)<k) left=pivot+1;
            else right=pivot;
        }
        return nums[left-1]+k-missing(left-1,nums);
    }
};