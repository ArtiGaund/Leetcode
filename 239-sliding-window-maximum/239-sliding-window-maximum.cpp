class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int left=0;left<nums.size();left++)
        {
            if(dq.front()==left-k) dq.pop_front();
            while(!dq.empty() and nums[dq.back()]<nums[left]) dq.pop_back();
            dq.push_back(left);
            if(left-k+1>=0) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};