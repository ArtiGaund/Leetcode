class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> mp;
        for(char ch:s) mp[ch]++;
        priority_queue<char> maxHeap;
        for(auto &[ch,count]:mp){
            maxHeap.push(ch);
        }
        string res;
        while(!maxHeap.empty()){
            char ch=maxHeap.top();
            maxHeap.pop();
            int count=mp[ch];
            int use=min(count,repeatLimit);
            res.append(use,ch);
            mp[ch]-=use;
            if(mp[ch]>0 and !maxHeap.empty()){
                char nextCh=maxHeap.top();
                maxHeap.pop();
                res.push_back(nextCh);
                mp[nextCh]--;
                if(mp[nextCh]>0) maxHeap.push(nextCh);
                maxHeap.push(ch);
            }
        }
        return res;
    }
};