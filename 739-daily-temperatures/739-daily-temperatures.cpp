class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> dis(n);
        stack<pair<int,int>> mq;
        for(int i=n-1;i>=0;i--)
        {
            int val=temp[i];
            while(!mq.empty() and val>=mq.top().first) mq.pop();
            if(!mq.empty())
                dis[i]=mq.top().second-i;
            else
                dis[i]=0;
            mq.push({val,i});
        }
        return dis;
    }
};