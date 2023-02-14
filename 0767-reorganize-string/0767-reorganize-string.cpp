class Solution {
public:
    struct valComp
    {
        bool operator()(const pair<char,int> &x,const pair<char,int> &y)
        {
            return y.second>x.second;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char ch:s) mp[ch]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,valComp> maxHeap;
        for(auto it:mp) maxHeap.push(it);
        pair<char,int> prev(-1,-1);
        string res="";
        while(!maxHeap.empty())
        {
            pair<char,int> cur=maxHeap.top();
            maxHeap.pop();
            if(prev.second>0) maxHeap.push(prev);
            res+=cur.first;
            cur.second--;
            prev=cur;
        }
        return res.size()==s.size()?res:"";
    }
};