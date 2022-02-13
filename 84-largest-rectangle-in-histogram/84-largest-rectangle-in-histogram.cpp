class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        int maxArea=0;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            int start=i;
            while(!st.empty() and st.top().second>heights[i])
            {
                int index=st.top().first;
                int h=st.top().second;
                st.pop();
                maxArea=max(maxArea,h*(i-index));
                start=index;
            }
            st.push({start,heights[i]});
        }
        while(!st.empty())
        {
            int index=st.top().first;
            int h=st.top().second;
            st.pop();
            maxArea=max(maxArea,h*(n-index));
        }
        return maxArea;
    }
};