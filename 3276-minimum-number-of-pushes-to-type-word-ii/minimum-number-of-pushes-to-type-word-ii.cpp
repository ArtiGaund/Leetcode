class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(char ch:word) mp[ch]++;
        priority_queue<int> pq;
        for(auto it:mp) pq.push(it.second);
        int totalPushes=0;
        int index=0;
        while(!pq.empty()){
            totalPushes+=(1+index/8)*pq.top();
            pq.pop();
            index++;
        }
        return totalPushes;
    }
};