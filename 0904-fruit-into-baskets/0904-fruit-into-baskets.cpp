class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n==0) return 0;
        int start=0,maxlen=0;
        unordered_map<int,int> mp;
        for(int end=0;end<n;end++)
        {
            mp[fruits[end]]++;
            while((int)mp.size()>2)
            {
                if(mp[fruits[start]]==1) mp.erase(fruits[start]);
                else mp[fruits[start]]--;
                start++;
            }
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};