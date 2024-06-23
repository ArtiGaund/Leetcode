class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD,minD;
        int left=0,right;
        int maxLen=0;
        for(right=0;right<nums.size();right++){
            while(!maxD.empty() and maxD.back()<nums[right]){
                maxD.pop_back();
            }
            maxD.push_back(nums[right]);
            while(!minD.empty() and minD.back()>nums[right]){
                minD.pop_back();
            }
            minD.push_back(nums[right]);
            while(maxD.front()-minD.front()>limit){
                if(maxD.front()==nums[left]){
                    maxD.pop_front();
                }
                if(minD.front()==nums[left]){
                    minD.pop_front();
                }
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};