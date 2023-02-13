class Solution {
public:
    struct valComp
    {
        bool operator()(const pair<char,int> &x,const pair<char,int> &y)
        {
            return y.second>x.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch:s) mp[ch]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,valComp> minHeap;
        for(auto it:mp)
            minHeap.push({it.first,it.second});
        string res="";
        while(!minHeap.empty())
        {
            char ch=minHeap.top().first;
            int size=minHeap.top().second;
            minHeap.pop();
            for(int i=0;i<size;i++)
                res+=ch;
        }
        return res;
    }
};