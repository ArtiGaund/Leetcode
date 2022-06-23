class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        unordered_set<int> vis;
        q.push(id);
        vis.insert(id);
        while(level>0)
        {
            level--;
            int size=q.size();
            while(size--)
            {
                int j=q.front();
                q.pop();
                for(int x:friends[j])
                {
                    if(vis.count(x)==0) 
                    {
                        q.push(x);
                        vis.insert(x);
                    }
                }
            }
        }
        unordered_map<string,int> mp;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(string str:watchedVideos[x])
            {
                if(mp.count(str)==0) mp[str]=0;
                else mp[str]++;
            }
        }
        vector<pair<int,string>> temp;
        for(auto it=mp.begin();it!=mp.end();it++) temp.push_back({it->second,it->first});
        sort(temp.begin(),temp.end());
        vector<string> res(temp.size());
        for(int i=0;i<temp.size();i++)
            res[i]=temp[i].second;
        return res;
    }
};