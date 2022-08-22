class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0,maxlen=0,maxRepeatOne=0;
        for(int end=0;end<n;end++)
        {
            if(nums[end]==1) maxRepeatOne++;
            if(end-start+1-maxRepeatOne>k)
            {
                if(nums[start]==1) maxRepeatOne--;
                start++;
            }
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};