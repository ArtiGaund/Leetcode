class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:mp) pq.push({it.second,it.first});
        string res="";
        pair<int,char> prev={-1,'#'};
        while(!pq.empty())
        {
            pair<int,char> top=pq.top();
            pq.pop();
            res+=top.second;
            if(prev.first>0) pq.push(prev);
            (top.first)--;
            prev=top;
        }
        if(res.size()!=s.size()) return "";
        return res;
    }
};