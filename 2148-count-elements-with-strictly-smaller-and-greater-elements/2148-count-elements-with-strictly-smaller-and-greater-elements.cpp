class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int i=1;
        while(i<nums.size()-1)
        {
            bool f1=false,f2=false;
            for(int start=0;start<i;start++)
            {
                if(nums[start]<nums[i])
                {
                    f1=true;
                    break;
                }
            }
            for(int end=i+1;end<nums.size();end++)
            {
                if(nums[i]<nums[end])
                {
                    f2=true;
                    break;
                }
            }
            if(f1 and f2) res++;
            i++;
        }
        return res;
    }
};