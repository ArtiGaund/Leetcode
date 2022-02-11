class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k==0) return s;
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
            pq.push({it.second,it.first});
        int len=s.size();
        string res="";
        while(!pq.empty())
        {
            vector<pair<int,char>> cache;
            int count=min(k,len);
            for(int i=0;i<count;i++)
            {
                if(pq.empty()) return "";
                auto temp=pq.top();
                pq.pop();
                res+=temp.second;
                if(--temp.first>0) cache.push_back(temp);
                len--;
            }
            for(auto a:cache) pq.push(a);
        }
        return res;
    }
};