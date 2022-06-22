class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> maxH;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            maxH.push(nums[i]);
            if(maxH.size()>k) maxH.pop();
        }
        return maxH.top();
    }
};