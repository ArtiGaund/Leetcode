class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int> q;
        int time=0;
        for(auto c:courses)
        {
            if(time+c[0]<=c[1])
            {
                q.push(c[0]);
                time+=c[0];
            }
            else if(!q.empty() and q.top()>c[0])
            {
                time+=c[0]-q.top();
                q.pop();
                q.push(c[0]);
            }
        }
        return q.size();
    }
};