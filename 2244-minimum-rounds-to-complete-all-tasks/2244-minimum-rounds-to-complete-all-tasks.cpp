class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int a:tasks) mp[a]++;
        int minRounds=0;
        for(auto [task,count]:mp)
        {
            if(count==1) return -1;
            if(count%3==0) minRounds+=count/3;
            else
            {
                minRounds+=count/3+1;
            }
        }
        return minRounds;
    }
};