class Solution {
public:
int largestRectangleArea(vector<int> &heights){
    int n=heights.size();
    int maxArea=0;
    stack<int> st;
    for(int i=0;i<=n;i++){
        while(!st.empty() and (i==n or heights[st.top()]>heights[i])){
            int height=heights[st.top()];
            st.pop();
            int width;
            if(st.empty()) width=i;
            else width=i-st.top()-1;
            maxArea=max(maxArea,width*height);
        }
        st.push(i);
    }
    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int maxArea=0;
        vector<int> heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area=largestRectangleArea(heights);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};