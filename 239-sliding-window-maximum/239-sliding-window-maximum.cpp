class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int left=0;left<nums.size();left++)
        {
            if(dq.front()==left-k)// as window move on, element nums[left-k] will be outdated
                dq.pop_front();
            // push nums[i] in window but before that remove the elements from deque back whose element is less than             // it bz we want max value
            while(!dq.empty() and nums[dq.back()]<nums[left]) dq.pop_back();
            dq.push_back(left); //push cur val
            if(left-k+1>=0) res.push_back(nums[dq.front()]); //if window is of k size
        }
        return res;
    }
};