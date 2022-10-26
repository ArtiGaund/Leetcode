class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        int prev=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int d=k?sum%k:sum;
            if(st.find(d)!=st.end()) return true;
            st.insert(prev);
            prev=d;
        }
        return false;
    }
};