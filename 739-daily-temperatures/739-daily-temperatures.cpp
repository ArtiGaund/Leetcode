class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> dis(n); //will keep the dis between cur elem and next greater element;
        stack<pair<int,int>> mq; //monotonic queue for non increasing sequence
        for(int i=n-1;i>=0;i--)
        {
            int val=temp[i];
            while(!mq.empty() and val>=mq.top().first)
                mq.pop();
            if(!mq.empty())
                dis[i]=mq.top().second-i;
            else
                dis[i]=0;
            mq.push({temp[i],i});
        }
        return dis;
        
    }
};