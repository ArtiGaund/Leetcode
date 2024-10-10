class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() or nums[st.top()]>nums[i]) st.push(i);
        }
        int maxWidth=0;
        for(int j=n-1;j>=0;j--){
            while(!st.empty() and nums[st.top()]<=nums[j]){
                maxWidth=max(maxWidth,j-st.top());
                st.pop();
            }
        }
        return maxWidth;
    }
};