class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        s.push(-1);
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 and heights[s.top()]>=heights[i])
            {
                int cur_h=heights[s.top()];
                 s.pop();
                int cur_width=i-s.top()-1;
               
                maxArea=max(maxArea,cur_h*cur_width);
            }
            s.push(i);
        }
        while(s.top()!=-1)
        {
            int cur_h=heights[s.top()];
             s.pop();
            int cur_width=n-s.top()-1;
           
            maxArea=max(maxArea,cur_h*cur_width);
        }
        return maxArea;
    }
};