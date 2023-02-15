class Solution {
public:
    struct valComp
    {
        bool operator()(const pair<char,int> &x,const pair<char,int> &y)
        {
            return y.second>x.second;
        }
    };
    int leastInterval(vector<char>& tasks, int k) {
      unordered_map<char,int> mp;
        for(char ch:tasks) mp[ch]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,valComp> maxHeap;
        for(auto it:mp) maxHeap.push(it);
        int intervalCount=0;
        while(!maxHeap.empty())
        {
            vector<pair<char,int>> waitList;
            int n=k+1;
            for(;n>0 and !maxHeap.empty();n--)
            {
                intervalCount++;
                auto cur=maxHeap.top();
                maxHeap.pop();
                if(cur.second>1)
                {
                    cur.second--;
                    waitList.push_back(cur);
                }
            }
            for(auto it:waitList) maxHeap.push(it);
            if(!maxHeap.empty()) intervalCount+=n;
        }
        return intervalCount;
    }
};