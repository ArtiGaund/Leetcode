class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxH;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        for(int i=0;i<profits.size();i++)
            minH.push({capital[i],profits[i]});
        for(int i=0;i<k;i++)
        {
            while(!minH.empty() and minH.top().first<=w)
            {
                maxH.push(minH.top().second);
                minH.pop();
            }
            if(maxH.empty()) return w;
            w+=maxH.top();
            maxH.pop();
        }
        return w;
    }
};