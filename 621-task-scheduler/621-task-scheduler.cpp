class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char ch:tasks) mp[ch]++;
        priority_queue<int> maxH;
        for(auto it:mp)
            maxH.push(it.second);
        int res=0;
        int cycle=n+1;
        while(!maxH.empty())
        {
            int time=0;
            vector<int> temp;
            for(int i=0;i<cycle;i++)
            {
                if(!maxH.empty())
                {
                    temp.push_back(maxH.top());
                    maxH.pop();
                    time++;
                }
            }
            for(auto it:temp)
            {
                if(--it) maxH.push(it);
            }
            res+=(!maxH.empty()?cycle:time);
        }
        return res;
    }
};