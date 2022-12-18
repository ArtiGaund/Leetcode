class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> dist(n);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--)
        {
            int val=temp[i];
            while(!st.empty() and val>=st.top().first) st.pop();
            if(!st.empty()) dist[i]=st.top().second-i;
            else dist[i]=0;
            st.push({val,i});
        }
        return dist;
    }
};