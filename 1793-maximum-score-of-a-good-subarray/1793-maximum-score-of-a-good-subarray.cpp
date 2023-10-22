class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> left(n,-1),st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.back()]>nums[i])
            {
                left[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
        }
        vector<int> right(n,n);
        st.clear();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and nums[st.back()]>nums[i])
            {
                right[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(left[i]<k and right[i]>k)
                res=max(res,nums[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};