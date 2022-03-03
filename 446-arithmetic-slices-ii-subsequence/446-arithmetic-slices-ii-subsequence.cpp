class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        int ans=0;
        vector<unordered_map<int,int>> mp(n);
        for(int i=0;i<n;i++)
        {
            int j=i-1;
            while(j>=0)
            {
                //given contraints are prone of overflow so
                long diff=(long)A[i]-(long)A[j];
                if(diff<=INT_MIN or diff>=INT_MAX)
                {
                    j--;
                    continue;
                }
                if(mp[j].find(diff)!=mp[j].end())
                {
                    int curaps=mp[i][(int)diff];
                    int prevaps=mp[j][(int)diff];
                    ans+=prevaps;
                    mp[i][diff]=curaps+prevaps+1;
                }
                else
                    mp[i][diff]++;
                j--;
            }
        }
        return ans;
    }
};