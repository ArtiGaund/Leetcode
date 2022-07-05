class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int a:nums) s.insert(a);
        int maxlen=0;
        for(int a:s)
        {
            if(s.count(a-1)==0)
            {
                int cur=a;
                int len=1;
                while(s.count(cur+1))
                {
                    cur+=1;
                    len+=1;
                }
                maxlen=max(maxlen,len);
            }
        }
        return maxlen;
    }
};