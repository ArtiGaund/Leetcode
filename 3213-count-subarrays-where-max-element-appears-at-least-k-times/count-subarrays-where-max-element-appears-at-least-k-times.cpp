class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle=*max_element(nums.begin(),nums.end());
        long long res=0,start=0;
        int maxEleInWindow=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==maxEle) maxEleInWindow++;
            while(maxEleInWindow==k){
                if(nums[start]==maxEle) maxEleInWindow--;
                start++;
            }
            res+=start;
        }
        return res;
    }
};