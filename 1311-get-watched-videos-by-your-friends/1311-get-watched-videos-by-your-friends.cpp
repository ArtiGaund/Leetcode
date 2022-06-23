class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // part 1: bfs to get frnds of id at level k
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
        // q contains frnds at level k
        // part 2: get watched movies of level k frnds and sort them
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
      vector<pair<int, string>> pairs;
        for (auto it = mp.begin(); it!=mp.end(); it++){
            pairs.push_back({it->second, it->first});
        }
        sort(pairs.begin(), pairs.end());
        vector<string> result(pairs.size());
        for (int i = 0; i < pairs.size(); i++){
            result[i] = pairs[i].second;
        }
        return result;
    }
};