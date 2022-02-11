typedef pair<char,int> pic;
class Solution {
public:
    struct compare
    {
        bool operator()(pic p1,pic p2)
        {
            return p1.second<p2.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pic,vector<pic>,compare> pq;
        for(auto it:mp)
        {
            pq.push({it.first,it.second});
        }
        string res="";
        while(!pq.empty())
        {
            for(int i=0;i<pq.top().second;i++)
                res+=pq.top().first;
            pq.pop();
        }
        return res;
    }
};